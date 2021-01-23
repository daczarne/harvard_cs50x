#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
  // Check that there are two values in argv (./caesar and key)
  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  // Check if the key is a positive integer
  bool is_positive_integer = true;
  // If the first char is a - then it's not a positive integer
  if (argv[1][1] == 45)
  {
    is_positive_integer = false;
  }
  // If the flag is still true...
  if (is_positive_integer)
  {
    // ...check that every char is a digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
      if (argv[1][i] < 48 || argv[1][i] > 57)
      {
        is_positive_integer = false;
        break;
      }
    }
  }
  // If the flag changed, stop execution
  if (!is_positive_integer)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  // Get the key from the command line argument
  int key = atoi(argv[1]);
  // Prompt the user for plaintext input
  string plaintext = get_string("plaintext: ");
  // Return the ciphertext
  printf("ciphertext: ");
  for (int i = 0, n = strlen(plaintext); i < n; i++)
  {
    if (65 <= plaintext[i] && plaintext[i] <= 90)
    {
      printf("%c", (plaintext[i] - 65 + key) % 26 + 65);
    }
    else if (97 <= plaintext[i] && plaintext[i] <= 122)
    {
      printf("%c", (plaintext[i] - 97 + key) % 26 + 97);
    }
    else
    {
      printf("%c", plaintext[i]);
    }
  }
  printf("\n");
  return 0;
}