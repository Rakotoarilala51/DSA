def euler03(n):
    factor = 2
    while factor*factor<=n:
        if n%factor ==0:
            n//=factor
        factor+=1
    return n if n>1 else factor

print(euler03(600851475143))