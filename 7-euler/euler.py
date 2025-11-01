from decimal import Decimal, getcontext
from math import sqrt


def fib(n):
    dp=[0]*(n+1)
    dp[0]=dp[1]=1
    for i in range(2, n+1):
        dp[i]=dp[i-1]+dp[i-2]
    return dp

def even(n):
    return int((-10 + (5 - 3*sqrt(5))*(2 - sqrt(5))**n + (2 + sqrt(5))**n*(5 + 3*sqrt(5)))/20)

def evenFibSum(limit):
    a, b = 1, 2
    total = 0
    while b <= limit:
        if b % 2 == 0:
            total += b
        a, b = b, a + b
    return total
fibonacci = fib(100)
evenSum = []
sum = 0
for i in range(2, len(fibonacci)-2,3):
    sum += fibonacci[i]
    evenSum.append(sum)
print(evenSum)
print(evenFibSum(4_000_000))

