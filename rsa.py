#!/usr/bin/python3
from sys import argv

with open(argv[1]) as _file:
    for file_content in _file:
        num = int(file_content)
        print("{:d}=".format(num), end="")
        if num % 2 == 0:
            print("{}*2".format(num//2))
            continue
        for i in range(3, num, 2):
            if num % i == 0:
                num_fac = num//i
                for j in range(3, num_fac, 2):
                    if num_fac % j == 0 or i % j == 0:
                        break
                    print("{}*{}".format(num_fac, i))
                    break
