#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Prototypes
long get_cc_number(void);
int return_sum_of_digits(long cc_number);

int main(void)
{
  // Prompt the user for input
  long cc_number = get_cc_number();

  // Find the lenght of the input number
  int cc_length = floor(log10(cc_number)) + 1;

  // Checksum //
  int sum_digits = return_sum_of_digits(cc_number);

  // Init the validation flag in false
  bool valid_cc_number = false;

  // If the sum of digits ends in 0
  if (sum_digits % 10 == 0)
  {
    // Change the validation flag to true
    valid_cc_number = true;
  }

  // Check card lenght and starting digits
  string card_issuer = "INVALID";

  if (valid_cc_number)
  {
    if (cc_length == 15)
    {
      // Get first two digits of a 15 digit long number
      int cc_start = cc_number / 10000000000000;

      // If those digits are 34 or 37 change the card issuer to AMEX
      if (cc_start == 34 || cc_start == 37)
      {
        card_issuer = "AMEX";
      }
    }
    else if (cc_length == 13)
    {
      // Get the first digit of a 13 digit long number
      int cc_start = cc_number / 1000000000000;

      // If that number is 4 then change the card issuer to VISA
      if (cc_start == 4)
      {
        card_issuer = "VISA";
      }
    }
    else if (cc_length == 16)
    {
      // Get first digit
      int cc_start = cc_number / 1000000000000000;

      // If the first digit is 4 change card issuer to VISA
      if (cc_start == 4)
      {
        card_issuer = "VISA";
      }
      else
      {
        // Get the first two digits
        cc_start = cc_number / 100000000000000;

        // If the card starts with 51 or 55 change the card issuer to MASTERCARD
        if (cc_start == 51 || cc_start == 55)
        {
          card_issuer = "MASTERCARD";
        }
      }
    }
  }

  // Print result
  printf("%s\n", card_issuer);
}

// User input function
long get_cc_number(void)
{

  long l;
  do
  {
    l = get_long("Number: ");
  } while (l < 0);
  return l;
}

// Return sum of digits
int return_sum_of_digits(long cc_number)
{
  // Find the lenght of the input number
  int cc_length = floor(log10(cc_number)) + 1;

  // Init sums for evens and odds
  int sum_evens = 0;
  int sum_odds = 0;

  for (int i = 0; i < cc_length; i++)
  {
    // Get the last digit (the one to be evaluated)
    int last_digit = cc_number % 10;

    // If the digit is in an odd position
    if (i % 2 != 0)
    {
      // Build de sum term
      int sum_term = last_digit * 2;

      // Find the length of the sum term
      int sum_term_length = floor(log10(sum_term)) + 1;

      // If the sum term is greater than 9
      if (sum_term_length == 2)
      {
        // Get the units position and the tens position
        int units = sum_term % 10;
        int tens = sum_term / 10;

        // Add units and tens together
        sum_term = units + tens;
      }

      // Add the sum term to the accumulated sum of odds
      sum_odds += sum_term;
    }
    else
    {
      // If the last digit is not odd (ie, it's even) add it to the evens
      sum_evens += last_digit;
    }

    // Drop the last digit
    cc_number = cc_number / 10;
  }

  // Add the sum of evens and odds
  int sum_digits = sum_evens + sum_odds;

  // Return value
  return sum_digits;
}
