#!/usr/bin/python3
from sys import argv
from math import sqrt
def factor(num):
    if num % 2 == 0:
        yield 2
        while num % 2 == 0:
            num //= 2
    for i in range(3, int(sqrt(num)) + 1, 2):
        if num % i == 0:
            yield i
            while num % i == 0:
                num //= i
    
    if num > 2:
        yield num


with open(argv[1]) as _file:
    for file_content in _file:
        num = int(file_content)
        print("{:d}=".format(num), end="")
        if num % 2 == 0:
            print("{}*2".format(num//2))
            continue
        for i in factor(num):
            print("{}*{}".format(num//i, i))
            break
        print()
