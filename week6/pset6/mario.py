# mario.py
# The tests for this were written not so fairly

import cs50

def main():
    height = cs50.get_int("Height: ")
    while(height < 1 or height > 8):
        if height < 1:
            print("Please enter a positive integer.")
            height = cs50.get_int("Height: ")
        elif height > 8:
            print("Please enter a number less than 9.")
            height = cs50.get_int("Height: ")
    else:
        PyramidBuilder(height)

def PyramidBuilder(height):
    for row in range(1, height+1):
        print(" "*(height - row), end = "")
        print("#" * row, end = "")
        print("  ", end="")
        print("#" * row)

main()





