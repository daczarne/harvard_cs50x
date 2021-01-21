#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
  // Prompt the user for some text input
  string text = get_string("Text: ");

  // Count words, letters, and sentences
  int words = 0;
  int letters = 0;
  int sentences = 0;

  for (int i = 0, n = strlen(text); i <= n; i++)
  {
    if (65 <= toupper(text[i]) && toupper(text[i]) <= 90)
    {
      letters++;
    }
    else if (text[i] == 46 || text[i] == 33 || text[i] == 63)
    {
      sentences++;
    }
    else if (text[i] == 32 || text[i] == '\0')
    {
      words++;
    }
  }

  // Calculate L and S
  float L = letters * 100.00 / words;
  float S = sentences * 100.00 / words;

  // Compute Coleman-Liau index
  int index = round(0.0588 * L - 0.296 * S - 15.8);

  // Return message
  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index > 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", index);
  }
}
