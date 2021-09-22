from cs50 import get_int

# scores = [72, 73, 33]

# print("Average: " + str((sum(scores) / len(scores))))

# print(f"Average:  {sum(scores) / len(scores)} ")

# average = (sum(scores) / len(scores))
# print(f"Average : {average}")

# print()
# print()
# ################################################
# print("Another way of doing the scores codes")

scores = []

for i in range(3):
    scores.append(get_int("Enter your three scores: "))

average = (sum(scores) / len(scores))
print(f"Average: {average}")