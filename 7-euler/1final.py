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


def euler_30():
    sum=0
    power=[i**5 for i in range(0,10)]
    all_number = []
    def sum_of_digit(n):
        result =0
        while(n>0):
            d=n%10
            result+=power[d]
            n//=10
        return result
    for i in range(2,354295):
        if sum_of_digit(i)==i:
            sum+=i
            all_number.append(i)
    return sum

def euler_36(n,k):
    def generate_palindrome(n, odd):
        res = n
        if odd:
            n//=10
        while n>0:
            res = res*10+n%10
            n//=10
        return res
    def is_palindrome(n, base):
        temp = n
        reversed = 0
        while temp>0:
            reversed = reversed*base + temp%base
            temp //= base
        return n==reversed
    