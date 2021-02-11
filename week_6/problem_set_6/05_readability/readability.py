# Prompt the user for input
text = input("Text: ")

# Define variables
words = len(text.rsplit())
letters = 0
sentences = 0

# Count
for character in text:
    if 65 <= ord(character.upper()) <= 90:
        letters += 1
    elif ord(character) in [33, 46, 63]:
        sentences += 1

# Calculate L and S
L = letters * 100.00 / words
S = sentences * 100.00 / words

# Calculate index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Evaluate condition and print
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
