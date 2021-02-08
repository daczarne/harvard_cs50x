# Prompt the user for input
while True:
    try:
        height = int(input("Height: "))
        if 1 <= height <= 8:
            break
    except ValueError as ex:
        pass

# Print the blocks
for i in range(height):
    for j in range(height):
        if j >= (height - (i + 1)):
            print("#", end="")
        else:
            print(" ", end="")
    print("\n", end="")
