# replicating hello.py without cs50 library

# answer = input("What's your name?")
# print(f"hello, {answer}")

# Moving on to replication addition.c

from cs50 import get_int

# Prompt user for x
x = get_int(" x :")

# Prompt user for y
y = get_int("y : ")

# perform addition
print(x + y)