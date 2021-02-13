#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Find the winner
    string winner;

    if (score1 == score2)
    {
        winner = "Tie!";
    }
    else if (score1 > score2)
    {
        winner = "Player 1 wins!";
    }
    else
    {
        winner = "Player 2 wins!";
    }

    // Print the winner
    printf("%s\n", winner);
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int letter_position = (int) tolower(word[i]) - 97;
        if (0 <= letter_position && letter_position <= 25)
        {
            score += POINTS[letter_position];
        }
    }
    return score;
}