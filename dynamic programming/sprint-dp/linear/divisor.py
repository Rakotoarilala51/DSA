from math import sqrt

def generatePrimes(n):
    isPrime = [True]*(n+1)
    isPrime[0]=isPrime[1]=False
    for i in range(2, n+1):
        if isPrime[i]:
            for j in range(i*i, n+1, i):
                isPrime[j]=False
    primes = [i for i, prime in enumerate(isPrime) if prime]
    
    return primes

def productInt(n, subresult, result):
    if(n==1):
        result.append(subresult[:])
        return
    for i in range(2, n+1):
        if n%i==0:
            subresult.append(i)
            productInt(n//i, subresult, result)
            subresult.pop()

def isTriangulanr(k):
    n = int(sqrt(k*2))
    return ((n*(n+1))//2) == k

def minimum_num(n):
    primes = generatePrimes(100)
    product_int= [] 
    productInt(n, [], product_int)
    ans = float('inf')
    real_ans = 0
    for nums in product_int:
        k=1
        prime_index = 0
        for i in nums:
            k *= primes[prime_index] ** (i-1)
            prime_index+=1
        print("k==", k)
        if isTriangulanr(k):
            print(k)
            ans = min(ans, k)

    return ans

minimum_num(6)