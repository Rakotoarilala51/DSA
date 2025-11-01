from numpy import lcm


def euler_5(n):
    result = 1
    for i in range(1,n+1):
        result = lcm(result, i)
    return result

def euler_6(n):
    def sum_of_square(n):
        return n*(n+1)*(2*n+1)//6
    def square_of_sum(n):
        return ((n*(n+1))//2)**2
    return square_of_sum(n)-sum_of_square(n)


sum=0
m=1
while(sum<1000):
    if m&1:
        sum=m+((m**2)-1)//2+((m**2)+1)//2
    else:
        sum=m+((m**2)-4)//4+((m**2)+4)//4
    m+=1


def euler_28(n):
    return ((4*n**3)+(3*n**2)+(8*n)-9)//6

print(euler_28(1001))
    