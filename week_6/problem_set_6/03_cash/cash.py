# Prompt the user for input
while True:
    try:
        dollars = float(input("Change owed: "))
        if dollars >= 0:
            break
    except ValueError as ex:
        pass

# Transform value into cents
cents = int(dollars * 100)

# Find the number of quarters
quarters = int(cents / 25)
change_owed = cents - (quarters * 25)

# Find the number of dimes
dimes = int(change_owed / 10)
change_owed = change_owed - (dimes * 10)

# Find the number of dimes
nickels = int(change_owed / 5)
change_owed = change_owed - (nickels * 5)

# Find number of total coins
coins = quarters + dimes + nickels + change_owed

# Print number of coins
print(coins)
