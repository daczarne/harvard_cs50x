from math import floor, log


def sum_of_digits(cc_number):
    cc_length = int(floor(log(cc_number, 10)) + 1)
    sum_evens = 0
    sum_odds = 0
    for i in range(cc_length + 1):
        # Get the last digit (the one to be evaluated)
        last_digit = int(cc_number % 10)
        # If the digit is in an odd position
        if i % 2 != 0:
            # Build de sum term
            sum_term = last_digit * 2
            # If the sum term is greater than 9
            if sum_term >= 10:
                # Get the units position and the tens position
                units = int(sum_term % 10)
                tens = int(sum_term / 10)
                # Add units and tens together
                sum_term = units + tens
            # Add the sum term to the accumulated sum of odds
            sum_odds += sum_term
        # If the last digit is not odd (ie, it's even)...
        else:
            # ...add it to the evens
            sum_evens += last_digit
        # Drop the last digit
        cc_number = int(cc_number / 10)
    # Return sum
    return (sum_evens + sum_odds)


# Prompt the user for input
while True:
    try:
        cc_number = input("Number: ")
        if int(cc_number) > 0:
            break
    except ValueError as ex:
        pass

cc_number = int(cc_number)
cc_length = int(floor(log(cc_number, 10)) + 1)
sum_digits = sum_of_digits(cc_number)

# Check if cc number is valid
valid_cc_number = False
if sum_digits % 10 == 0:
    # Change the validation flag to true
    valid_cc_number = True

# Find card issuer
card_issuer = "INVALID"

if valid_cc_number:
    if cc_length == 15:
        # Get first two digits of a 15 digit long number
        cc_start = int(cc_number / 10000000000000)
        # If those digits are 34 or 37 change the card issuer to AMEX
        if cc_start == 34 or cc_start == 37:
            card_issuer = "AMEX"

    elif cc_length == 13:
        # Get the first digit of a 13 digit long number
        cc_start = int(cc_number / 1000000000000)
        # If that number is 4 then change the card issuer to VISA
        if cc_start == 4:
            card_issuer = "VISA"

    elif cc_length == 16:
        # Get first digit
        cc_start = int(cc_number / 1000000000000000)
        # If the first digit is 4 change card issuer to VISA
        if cc_start == 4:
            card_issuer = "VISA"
        else:
            # Get the first two digits
            cc_start = int(cc_number / 100000000000000)
            # If the card starts with 51 or 55 change the card issuer to MASTERCARD
            if cc_start == 51 or cc_start == 55:
                card_issuer = "MASTERCARD"


print(card_issuer)
