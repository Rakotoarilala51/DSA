from math import log


def nth_prime(n):
    return (int(n//log(n)))

print(nth_prime(40000000))