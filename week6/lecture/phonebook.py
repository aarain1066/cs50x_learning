from cs50 import get_string

people = {
    "David": "1+727-555-5555",
    "Brian": "1+813-555-5555"
}

name = get_string("Name: ")
for name in people:
    print(f"Phone Number:, {people[name]}")