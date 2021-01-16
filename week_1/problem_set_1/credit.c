#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
  // Prompt the user for input
  long cc_number = get_long("Number: ");

  // Checksum //

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

      // Find the lengtgh of the sum term
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

      // Add the sum term to the accumulated sum od odds
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
      card_issuer = "AMEX\n";
    }
    else if (cc_length == 13)
    {
      card_issuer = "VISA\n";
    }
    else if (cc_length == 16)
    {
      card_issuer = "?";
    }
  }

  // Print result
}
