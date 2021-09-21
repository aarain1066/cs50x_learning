# replicating hello.py without cs50 library

# answer = input("What's your name?")
# print(f"hello, {answer}")

# Moving on to replication addition.c

# Prompt user for x
x = input("x :")

# Prompt user for y
y = input("y : ")

# perform addition
print(x + y, "incorrect way to add inputs")

# However, this is incorrect. We're looking for addtion and instead
# we are only getting the ints next to each other.

# We can fix it as so.

# Prompt user for x
x = int(input("x :"))

# Prompt user for y
y = int(input("y : "))

# perform addition
print(x + y, "correct way! cast inputs as ints")


