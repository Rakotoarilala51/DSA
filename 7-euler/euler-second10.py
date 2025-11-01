# Project Euler 11 -> 20 — solutions Python optimisées
# Python 3.8+
import math
import datetime
from functools import lru_cache
from math import prod, gcd

# -------------------------
# 11 — Largest product in a grid (4 adjacent)
# O( rows*cols ), simple scans horizontale/verticale/diag
def euler11(grid, k=4):
    rows = len(grid)
    cols = len(grid[0])
    best = 0
    for r in range(rows):
        for c in range(cols):
            # right
            if c + k <= cols:
                best = max(best, prod(grid[r][c + i] for i in range(k)))
            # down
            if r + k <= rows:
                best = max(best, prod(grid[r + i][c] for i in range(k)))
            # diag down-right
            if r + k <= rows and c + k <= cols:
                best = max(best, prod(grid[r + i][c + i] for i in range(k)))
            # diag down-left
            if r + k <= rows and c - k + 1 >= 0:
                best = max(best, prod(grid[r + i][c - i] for i in range(k)))
    return best

# -------------------------
# 12 — Triangular number with >500 divisors
# Use prime list + factorization; count divisors via exponent product
def primes_up_to(n):
    sieve = bytearray(b'\x01') * (n + 1)
    sieve[0:2] = b'\x00\x00'
    for i in range(2, int(n**0.5) + 1):
        if sieve[i]:
            step = i
            start = i * i
            sieve[start:n+1:step] = b'\x00' * ((n - start)//step + 1)
    return [i for i, v in enumerate(sieve) if v]

_primes_cache = primes_up_to(100000)  # assez grand pour factoriser les premiers candidats

def count_divisors(n):
    rem = n
    total = 1
    for p in _primes_cache:
        if p * p > rem:
            break
        if rem % p == 0:
            e = 0
            while rem % p == 0:
                rem //= p
                e += 1
            total *= (e + 1)
        if rem == 1:
            break
    if rem != 1:
        total *= 2
    return total

def euler12(limit=500):
    i = 1
    tri = 1
    while True:
        if count_divisors(tri) > limit:
            return tri
        i += 1
        tri += i

# -------------------------
# 13 — Large sum (first 10 digits of sum of 100 50-digit nums)
# Use Python int (arbitrary precision)
def euler13(numbers, first=10):
    s = sum(int(x) for x in numbers)
    return str(s)[:first]

# -------------------------
# 14 — Longest Collatz chain under 1_000_000
# Memoization + iterate odd/even step compressions
@lru_cache(maxsize=None)
def collatz_len(n):
    if n == 1:
        return 1
    if n % 2 == 0:
        return 1 + collatz_len(n // 2)
    else:
        return 1 + collatz_len(3 * n + 1)

def euler14(limit=1_000_000):
    best_n = 1
    best_l = 1
    for i in range(2, limit):
        l = collatz_len(i)
        if l > best_l:
            best_l = l
            best_n = i
    return best_n

# -------------------------
# 15 — Lattice paths 20x20 => C(40,20)
# Compute multiplicative to avoid huge factorials then reduce by gcd at each step
def nCr_mult(n, r):
    if r > n - r:
        r = n - r
    numer = 1
    denom = 1
    for i in range(r):
        numer *= (n - i)
        denom *= (i + 1)
        g = math.gcd(numer, denom)
        if g > 1:
            numer //= g
            denom //= g
    return numer // denom

def euler15(n=20):
    return nCr_mult(2 * n, n)

# -------------------------
# 16 — Power digit sum 2^1000
def euler16(exp=1000):
    s = pow(2, exp)
    return sum(int(ch) for ch in str(s))

# -------------------------
# 17 — Number letter counts 1..1000 (British usage includes 'and')
# Count letters (no spaces/hyphens)
_ones = {
    0: "", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five",
    6: "six", 7: "seven", 8: "eight", 9: "nine", 10: "ten",
    11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen",
    15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen",
    19: "nineteen"
}
_tens = {2: "twenty", 3: "thirty", 4: "forty", 5: "fifty",
         6: "sixty", 7: "seventy", 8: "eighty", 9: "ninety"}

def words_for(n):
    if n == 1000:
        return "one thousand"
    if n >= 100:
        h = n // 100
        rem = n % 100
        if rem == 0:
            return f"{_ones[h]} hundred"
        else:
            return f"{_ones[h]} hundred and {words_for(rem)}"
    if n >= 20:
        t = n // 10
        r = n % 10
        if r == 0:
            return _tens[t]
        else:
            return f"{_tens[t]}-{_ones[r]}"
    return _ones[n]

def euler17(limit=1000):
    total = 0
    for i in range(1, limit + 1):
        w = words_for(i)
        # remove spaces and hyphens
        total += len(w.replace(" ", "").replace("-", ""))
    return total

# -------------------------
# 18 — Maximum path sum (small triangle) dynamic programming bottom-up
def euler18(triangle):
    # triangle: list of lists
    # copy bottom-up to avoid modifying input
    dp = triangle[-1].copy()
    for row in range(len(triangle) - 2, -1, -1):
        new = []
        for i, val in enumerate(triangle[row]):
            new.append(val + max(dp[i], dp[i + 1]))
        dp = new
    return dp[0]

# -------------------------
# 19 — Counting Sundays on first of month in 20th century
def euler19(start_year=1901, end_year=2000):
    count = 0
    for y in range(start_year, end_year + 1):
        for m in range(1, 13):
            if datetime.date(y, m, 1).weekday() == 6:  # Sunday == 6
                count += 1
    return count

# -------------------------
# 20 — Factorial digit sum 100!
def euler20(n=100):
    f = math.factorial(n)
    return sum(int(ch) for ch in str(f))

# -------------------------
# Example usage / test with known inputs:
if __name__ == "__main__":
    # 11: provide the 20x20 grid as list of lists (example below truncated — replace with real grid)
    grid_20x20 = [
        [8,2,22,97,38,15,0,40,0,75,4,5,7,78,52,12,50,77,91,8],
        [49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62,0],
        [81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65],
        [52,70,95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91],
        [22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80],
        [24,47,32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50],
        [32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70],
        [67,26,20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21],
        [24,55,58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72],
        [21,36,23,9,75,0,76,44,20,45,35,14,0,61,33,97,34,31,33,95],
        [78,17,53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92],
        [16,39,5,42,96,35,31,47,55,58,88,24,0,17,54,24,36,29,85,57],
        [86,56,0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58],
        [19,80,81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40],
        [4,52,8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66],
        [88,36,68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69],
        [4,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36],
        [20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16],
        [20,73,35,29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54],
        [1,70,54,71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48],
    ]
    print("Euler 11:", euler11(grid_20x20))
    print("Euler 12:", euler12(500))
    # 13: provide the list of 100 50-digit numbers as strings in `numbers_100`
    # (not included here — put the 100 numbers in the list to run)
    # print("Euler 13:", euler13(numbers_100))
    print("Euler 14:", euler14())
    print("Euler 15:", euler15(20))
    print("Euler 16:", euler16(1000))
    print("Euler 17:", euler17(1000))
    # 18: you must pass the triangle as list of lists (small example)
    small_triangle = [
        [75],
        [95, 64],
        [17, 47, 82],
        [18, 35, 87, 10],
        [20, 04, 82, 47, 65],
    ]
    # replace above with the full triangle for the real result
    # print("Euler 18:", euler18(full_triangle))
    print("Euler 19:", euler19())
    print("Euler 20:", euler20(100))
