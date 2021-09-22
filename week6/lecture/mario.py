for i in range(3):
    print("#")

print("This is good, as the hash symbol we want to ve vertical, but what",
"about the question marks we want horizontally. ")

for i in range(4):
    print("?", end = "")
    print()

print("You can also use the end arg as...")

for i in range(4):
    print("?", end = "HELLO")
    print()

# We can also do
print("?" * 4, "Using multiple!")

print("And as well")
print()

for i in range(3):
    for j in range(3):
        print("#", end = "")
    print()