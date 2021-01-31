#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate avg pixel
            int avg_rgb = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Set new pixel values
            image[i][j].rgbtRed = avg_rgb;
            image[i][j].rgbtGreen = avg_rgb;
            image[i][j].rgbtBlue = avg_rgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get sepia red
            int sepia_red = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepia_red = (sepia_red > 255) ? 255 : sepia_red;

            // Get sepia green
            int sepia_green = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepia_green = (sepia_green > 255) ? 255 : sepia_green;

            // Get sepia blue
            int sepia_blue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            sepia_blue = (sepia_blue > 255) ? 255 : sepia_blue;

            // Build new pixels
            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, n = floor(width / 2.0); j < n; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avg_red;
    int avg_green;
    int avg_blue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Top-left corner
            if (i == 0 && j == 0)
            {
                // Compute avg red
                avg_red = round((image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 3.0);
                // Compute avg green
                avg_green = round((image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 3.0);
                // Compute avg blue
                avg_blue = round((image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 3.0);
            }
            // Top row, no corners
            else if (i == 0 && 0 < j && j < width)
            {
                // Compute avg red
                avg_red = round((image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 5.0);
                // Compute avg green
                avg_green = round((image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 5.0);
                // Compute avg blue
                avg_blue = round((image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 5.0);
            }
            // Top-right corner
            else if (i == 0 && j == width)
            {
                // Compute avg red
                avg_red = round((image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 3.0);
                // Compute avg green
                avg_green = round((image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 3.0);
                // Compute avg blue
                avg_blue = round((image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 3.0);
            }
            // Left column, no corners
            else if (j == 0 && 0 < i && i < height)
            {
                // Compute avg red
                avg_red = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 5.0);
                // Compute avg green
                avg_green = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 5.0);
                // Compute avg blue
                avg_blue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 5.0);
            }
            // Right column, no corners
            else if (j == width && i < 0 && i < height)
            {
                // Compute avg red
                avg_red = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 5.0);
                // Compute avg green
                avg_green = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 5.0);
                // Compute avg blue
                avg_blue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 5.0);
            }
            // Bottom left corner
            else if (i == height && j == 0)
            {
                // Compute avg red
                avg_red = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 3.0);
                // Compute avg green
                avg_green = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 3.0);
                // Compute avg blue
                avg_blue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 3.0);
            }
            // Bottom row, no corners
            else if (i == height && 0 < j && j < width)
            {
                // Compute avg red
                avg_red = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed) / 5.0);
                // Compute avg green
                avg_green = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 5.0);
                // Compute avg blue
                avg_blue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 5.0);
            }
            // Bottom right corner
            else if (i == height && j == width)
            {
                // Compute avg red
                avg_red = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed) / 3.0);
                // Compute avg green
                avg_green = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen) / 3.0);
                // Compute avg blue
                avg_blue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue) / 3.0);
            }
            // Middle pixels
            else
            {
                // Compute avg red
                avg_red = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 8.0);
                // Compute avg green
                avg_green = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 8.0);
                // Compute avg blue
                avg_blue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 8.0);
            }
            // Assign new values
            image[i][j].rgbtRed = avg_red;
            image[i][j].rgbtGreen = avg_green;
            image[i][j].rgbtBlue = avg_blue;
        }
    }
    return;
}
