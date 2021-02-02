#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage ./recover image\n");
    return 1;
  }

  // Open memory file
  FILE *card = fopen(argv[1], "r");
  if (card == NULL)
  {
    printf("Could not open file.\n");
    return 1;
  }

  // Init vars
  int end_of_file;
  int img_number = 0;
  bool found_first_pic = false;
  char filename[8];
  sprintf(filename, "%03i.jpg", img_number);
  FILE *image = fopen(filename, "w");
  if (card == NULL)
  {
    printf("Could not open file.\n");
    return 1;
  }

  // Get 512 bytes
  int buffer_size = 512;
  uint8_t buffer[buffer_size];

  while (fread(buffer, buffer_size, 1, card))
  {
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    {
      if (!found_first_pic)
      {
        // Change flag to true
        found_first_pic = true;

        // Start writing pic
        fwrite(buffer, buffer_size, 1, image);
      }
      else
      {
        // Close previous flag
        fclose(image);

        // Augment pic counter by one
        img_number++;

        // Create new file name
        sprintf(filename, "%03i.jpg", img_number);

        // Open file with new filename
        fopen(filename, "w");
        if (card == NULL)
        {
          printf("Could not open file.\n");
          return 1;
        }

        // Start writing to filename
        fwrite(buffer, buffer_size, 1, image);
      }
    }
    else
    {
      if (found_first_pic)
      {
        // Keep writing to opened file
        fwrite(buffer, buffer_size, 1, image);
      }
    }
  }

  // Close last image and card
  fclose(image);
  fclose(card);
}