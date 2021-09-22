from cs50 import get_int
from cs50 import get_string


x = get_int("x: ")
y = get_int("y: ")

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")

print("Moving on to another situation")


# agree.py


# s = get_string("Do you agree? : ")

# if s == "Y" or s == "y":
#     print("agreed!")
# elif s == "N" or s == "n":
#     print("disagreed!")

# a more general way to write agree.

s = get_string("Do you agree? ")

if s.lower() in ["y", "yes"]:
    print("Agreed!")
elif s.lower in ["n", "no"]:
    print("Disagreed!")
