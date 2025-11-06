from math import sqrt


def dp(n, s):
    if n==0:
        return 0
    if n<0:
        return float('inf')
    ans = float('inf')
    for i in s:
        ans=min(ans, 1+dp(n-i, s))
    return ans

def perfect_square(n):
    p = [i*i for i in range(1,int(sqrt(n))+1)]
    print(p)
    return dp(n, p)

print(perfect_square(46))