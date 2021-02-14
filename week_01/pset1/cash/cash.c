#include <stdio.h>
#include <math.h>
#include <cs50.h>

// Prototype
float get_dollars(void);

int main(void)
{
  // Prompt the user for input
  float dollars = get_dollars();

  // Convert to cents
  int cents = round(dollars * 100);

  // Find the number of quarters
  int quarters = cents / 25;
  int change_owed = cents - (quarters * 25);

  // Find the number of dimes
  int dimes = change_owed / 10;
  change_owed = change_owed - (dimes * 10);

  // Find the number of nickels
  int nickels = change_owed / 5;
  change_owed = change_owed - (nickels * 5);

  // Total number of coins
  int coins = quarters + dimes + nickels + change_owed;

  // Return the number of coins
  printf("%i\n", coins);
}

// User input function
float get_dollars(void)
{

  float f;
  do
  {
    f = get_float("Change owed: ");
  } while (f < 0);
  return f;
}