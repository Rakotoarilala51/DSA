def make_palindrome(n, odd):
    res = n
    if odd:
        n//=10
    while n>0:
        res = res*10+n%10
        n//=10
    return res
def is_palindrome(n,base):
    temp=n
    reversed=0
    while temp>0:
        reversed = reversed*base +temp%base
        temp//=base
    return reversed==n
def sum_palindrome(n,k):
    total = 0
    i=1
    p=make_palindrome(i,True)
    while(p<n):
        if(is_palindrome(p,k)):
            sum+=p
        i+=1
        p=make_palindrome(i,True)
        
    i=1
    p=make_palindrome(i,False)
    while p<n:
        if is_palindrome(p, k):
            sum+=p
        i+=1
        p=make_palindrome(i,False)
    return sum