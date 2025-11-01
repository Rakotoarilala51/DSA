def power_sequence(n,d):
    result = []
    for i in range(1,d):
        result.append(n**i)
    print(result[::-1])
    
power_sequence(5,5)