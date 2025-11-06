from math import log10


def sieve(n):
    prime=[1]*(n+1)
    prime[0]=prime[1]=0
    for i in range (2,int(n**0.5)+1):
        if prime[i]:
            for j in range(i*i, n+1, i):
                prime[j]=0
        
    return {i for i,is_prime in enumerate(prime)  if is_prime}

def circule(n, prime):
    unit = int(log10(n))
    cnt = unit
    result =n
    while cnt>0:
        result=result%10 * int(10**(unit))+ result//10
        if result not in prime:
            return False
        cnt-=1
    return True

def euler(n):
    primes = sieve(n)
    cnt =0
    for prime in primes:
        cnt+=circule(prime, primes)
    return cnt
        
print(euler(1000000))