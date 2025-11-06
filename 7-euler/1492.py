def kthFactor(n, k):
    if k>n:
        return -1
    factors=[]
    for i in range (1,n+1):
        if n%i==0:
            factors.append(i)
    if k-1>len(factors):
        return -1
    print(factors)
    return factors[k-1]
        

print(kthFactor(120,7))