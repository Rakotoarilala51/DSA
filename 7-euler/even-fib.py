def largestPrimeFactor(n):
    factor = 2
    while factor*factor<=n:
        while n %factor ==0:
            n//=factor
        factor+=1
    return n if n>1 else factor
print(largestPrimeFactor(600851475143))        