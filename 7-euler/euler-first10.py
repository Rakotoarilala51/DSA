"""
Project Euler Problems 1-10: Optimal Solutions
"""

# Problem 1: Multiples of 3 or 5
# Find the sum of all multiples of 3 or 5 below 1000
def problem_1(limit=1000):
    """
    O(1) solution using arithmetic series formula
    Sum = n(n+1)/2
    """
    def sum_divisible_by(n):
        p = (limit - 1) // n
        return n * p * (p + 1) // 2
    
    return sum_divisible_by(3) + sum_divisible_by(5) - sum_divisible_by(15)


# Problem 2: Even Fibonacci numbers
# Sum of even Fibonacci numbers not exceeding 4 million
def problem_2(limit=4_000_000):
    """
    O(log n) solution - only generate Fibonacci numbers up to limit
    Every 3rd Fibonacci number is even
    """
    a, b = 1, 2
    total = 0
    while b <= limit:
        if b % 2 == 0:
            total += b
        a, b = b, a + b
    return total


# Problem 3: Largest prime factor
# Largest prime factor of 600851475143
def problem_3(n=600851475143):
    """
    O(sqrt(n)) solution with trial division
    """
    factor = 2
    while factor * factor <= n:
        while n % factor == 0:
            n //= factor
        factor += 1
    return n if n > 1 else factor


# Problem 4: Largest palindrome product
# Largest palindrome from product of two 3-digit numbers
def problem_4():
    """
    O(n^2) but optimized by searching from largest to smallest
    """
    def is_palindrome(n):
        s = str(n)
        return s == s[::-1]
    
    max_palindrome = 0
    for i in range(999, 99, -1):
        if i * 999 <= max_palindrome:
            break
        for j in range(999, i - 1, -1):
            product = i * j
            if product <= max_palindrome:
                break
            if is_palindrome(product):
                max_palindrome = product
    return max_palindrome


# Problem 5: Smallest multiple
# Smallest number divisible by all numbers 1 to 20
def problem_5(n=20):
    """
    O(n log n) solution using LCM
    """
    from math import gcd
    
    def lcm(a, b):
        return a * b // gcd(a, b)
    
    result = 1
    for i in range(2, n + 1):
        result = lcm(result, i)
    return result


# Problem 6: Sum square difference
# Difference between sum of squares and square of sum (1 to 100)
def problem_6(n=100):
    """
    O(1) solution using formulas:
    Sum of first n numbers: n(n+1)/2
    Sum of squares: n(n+1)(2n+1)/6
    """
    sum_of_numbers = n * (n + 1) // 2
    square_of_sum = sum_of_numbers ** 2
    sum_of_squares = n * (n + 1) * (2 * n + 1) // 6
    return square_of_sum - sum_of_squares


# Problem 7: 10001st prime
def problem_7(n=10001):
    """
    O(n log log n) using Sieve of Eratosthenes with estimate
    """
    import math
    
    # Upper bound estimate for nth prime
    if n < 6:
        return [2, 3, 5, 7, 11][n - 1]
    
    limit = int(n * (math.log(n) + math.log(math.log(n))))
    
    # Sieve of Eratosthenes
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False
    
    for i in range(2, int(limit**0.5) + 1):
        if sieve[i]:
            for j in range(i*i, limit + 1, i):
                sieve[j] = False
    
    primes = [i for i, is_prime in enumerate(sieve) if is_prime]
    return primes[n - 1]


# Problem 8: Largest product in a series
# Greatest product of 13 adjacent digits
def problem_8():
    """
    O(n) solution with sliding window
    """
    number = """
    73167176531330624919225119674426574742355349194934
    96983520312774506326239578318016984801869478851843
    85861560789112949495459501737958331952853208805511
    12540698747158523863050715693290963295227443043557
    66896648950445244523161731856403098711121722383113
    62229893423380308135336276614282806444486645238749
    30358907296290491560440772390713810515859307960866
    70172427121883998797908792274921901699720888093776
    65727333001053367881220235421809751254540594752243
    52584907711670556013604839586446706324415722155397
    53697817977846174064955149290862569321978468622482
    83972241375657056057490261407972968652414535100474
    82166370484403199890008895243450658541227588666881
    16427171479924442928230863465674813919123162824586
    17866458359124566529476545682848912883142607690042
    24219022671055626321111109370544217506941658960408
    07198403850962455444362981230987879927244284909188
    84580156166097919133875499200524063689912560717606
    05886116467109405077541002256983155200055935729725
    71636269561882670428252483600823257530420752963450
    """.replace('\n', '').replace(' ', '')
    
    max_product = 0
    window_size = 13
    
    for i in range(len(number) - window_size + 1):
        product = 1
        for j in range(i, i + window_size):
            digit = int(number[j])
            if digit == 0:
                product = 0
                break
            product *= digit
        max_product = max(max_product, product)
    
    return max_product


# Problem 9: Special Pythagorean triplet
# Find a*b*c where a + b + c = 1000 and a^2 + b^2 = c^2
def problem_9(target=1000):
    """
    O(n^2) solution with early termination
    """
    for a in range(1, target // 3):
        for b in range(a + 1, (target - a) // 2):
            c = target - a - b
            if a * a + b * b == c * c:
                return a * b * c
    return None


# Problem 10: Summation of primes
# Sum of all primes below 2 million
def problem_10(limit=2_000_000):
    """
    O(n log log n) using Sieve of Eratosthenes
    """
    sieve = [True] * limit
    sieve[0] = sieve[1] = False
    
    for i in range(2, int(limit**0.5) + 1):
        if sieve[i]:
            for j in range(i*i, limit, i):
                sieve[j] = False
    
    return sum(i for i, is_prime in enumerate(sieve) if is_prime)


# Run all solutions
if __name__ == "__main__":
    problems = [
        (1, problem_1, "Multiples of 3 or 5"),
        (2, problem_2, "Even Fibonacci numbers"),
        (3, problem_3, "Largest prime factor"),
        (4, problem_4, "Largest palindrome product"),
        (5, problem_5, "Smallest multiple"),
        (6, problem_6, "Sum square difference"),
        (7, problem_7, "10001st prime"),
        (8, problem_8, "Largest product in a series"),
        (9, problem_9, "Special Pythagorean triplet"),
        (10, problem_10, "Summation of primes"),
    ]
    
    print("Project Euler Solutions 1-10\n" + "="*50)
    for num, func, description in problems:
        result = func()
        print(f"Problem {num:2d}: {result:12d} - {description}")