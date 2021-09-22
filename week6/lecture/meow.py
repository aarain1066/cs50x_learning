# meow.c



# for i in range(3):
#     meow()

# def meow():
#     print("meow")

# this (above) is the incorrect because python doesn't know the
# function before it is called.

# the proper way is to

def main():
    for i in range(3):
        meow()

def meow():
    print("meow")

main()
