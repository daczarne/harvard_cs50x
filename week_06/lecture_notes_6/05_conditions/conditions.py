# Conditions and relational operators

import cs50

# Prompt user for x
x = cs50.get_int("x: ")

# Prompt user for y
y = cs50.get_int("y: ")

# Compare x and y
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
