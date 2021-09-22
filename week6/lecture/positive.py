# translating from positive.c

from cs50 import get_int

def main():
    i = get_positive_int()
    print(i)

def get_positive_int():
    while True:
        n = get_int("Please enter a prositive integer: ")
        if n > 0:
            break
            # this break throws you back into the same line as while
            # so now, if n is actually > 0, the function return n
    return n

main()