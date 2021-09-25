import cs50

# make sure user enters valid input
height = 0
def main():
    while True:
        # Prompt user
        print("Height: ", end="")
        height = cs50.get_int()
        if height >= 0 and height <= 23:
            break

    # for every row
    for i in range(height):
        for j in range(height - i - 1):
            print(" ", end="")

        for k in range(i+2):
            print("#", end="")

        print(" ")

        for l in range(i+1):
            print("#")
        print("")

if __name__=="__main__":
    main()
