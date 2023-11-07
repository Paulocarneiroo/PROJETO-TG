def sum_odd(num1, num2):
    return num1 + num2 if num1 % 2 != 0 and num2 % 2 != 0 else 'Insira 2 números ímpares'


def is_even(n):
    return n % 2 == 0 

def factorial(n):
    sum = 1
    for i in range(n, 1, -1):
        sum *= i
    return sum

print(factorial(5))
#print(is_even(3))
#print(sum_odd(3,2))
#print(sum_odd(3,3))