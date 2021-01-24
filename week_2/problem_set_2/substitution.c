#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
  // Check that their are two args
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }
  // Check that the lenght of argv[1] is 26
  int key_length = strlen(argv[1]);
  if (key_length != 26)
  {
    printf("Key must contain 26 characters.\n");
    return 1;
  }
  // Check that every letter is included once in the key
  for (int i = 0, n = strlen(LETTERS); i < n; i++)
  {
    int counter = 0;
    for (int j = 0; j < key_length; j++)
    {
      // Everytime a letter is found, increase the counter by one
      if (tolower(LETTERS[i] == tolower(argv[1][j])))
      {
        counter++;
      }
      if (counter > 1)
      {
        printf("Each letter must appear only once in the key.\n");
        return 1;
      }
    }
    // If for any letter the counter is still 0 after checking all letters in the key
    // then the letter is not in the key
    if (counter == 0)
    {
      printf("Key must contain all letters in the English alphabet.\n");
      return 1;
    }
  }
  // Prompt the user for plaintext input
  string plaintext = get_string("plaintext: ");
  // Return the ciphertext
  printf("ciphertext: ");
  for (int i = 0, n = strlen(plaintext); i < n; i++)
  {
    if (isalpha(plaintext[i]))
    {
      if (islower(plaintext[i]))
      {
        printf("%c", tolower(argv[1][(plaintext[i] - 97)]));
      }
      if (isupper(plaintext[i]))
      {
        printf("%c", toupper(argv[1][(plaintext[i] - 65)]));
      }
    }
    else
    {
      printf("%c", plaintext[i]);
    }
  }
  printf("\n");
  return 0;
}