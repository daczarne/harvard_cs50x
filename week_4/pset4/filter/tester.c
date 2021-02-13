#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int rgbtBlue;
    int rgbtGreen;
    int rgbtRed;
}
RGBTRIPLE;

int main(void)
{
    RGBTRIPLE test_image[2];
    test_image[0].rgbtRed = 255;
    test_image[0].rgbtGreen = 0;
    test_image[0].rgbtBlue = 0;
    test_image[1].rgbtRed = 0;
    test_image[1].rgbtGreen = 0;
    test_image[1].rgbtBlue = 255;
    printf("(%i, %i, %i), ", test_image[0].rgbtRed, test_image[0].rgbtGreen, test_image[0].rgbtBlue);
    printf("(%i, %i, %i)\n", test_image[1].rgbtRed, test_image[1].rgbtGreen, test_image[1].rgbtBlue);
    printf("------------------\n");
    int height = 1;
    int width = 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, n = round(width / 2.0); j < n; j++)
        {
            printf("n = %i\n", n);
            printf("i = %i\n", i);
            printf("j = %i\n", j);
            printf("------------------\n");

            RGBTRIPLE temp = test_image[i];
            test_image[i] = test_image[width - 1];
            test_image[i] = temp;
        }
    }
    printf("(%i, %i, %i), ", test_image[0].rgbtRed, test_image[0].rgbtGreen, test_image[0].rgbtBlue);
    printf("(%i, %i, %i)\n", test_image[1].rgbtRed, test_image[1].rgbtGreen, test_image[1].rgbtBlue);
}
