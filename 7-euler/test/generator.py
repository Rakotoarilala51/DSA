def pow(a,b):
    result = 1
    while(b>0):
        if b&1:
            result*=a
        a*=a
        b>>=1
    return result

print(pow(2,20))