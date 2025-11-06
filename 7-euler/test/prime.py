from math import sqrt


def nth_prime(n):
    is_prime=[True]*(n+1)
    prime=[]
    is_prime[0]=is_prime[1]=False
    print(is_prime)
    for i in range(2, n+1):
        if is_prime[i]:
            for j in (i, int(sqrt(n)+1), i):
                is_prime[j]=False
    
    return is_prime

print(nth_prime(10))