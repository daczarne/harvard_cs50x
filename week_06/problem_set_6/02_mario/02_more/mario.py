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
    print(" " * (height - (i + 1)) + "#" * (i + 1) + "  " + "#" * (i + 1))
