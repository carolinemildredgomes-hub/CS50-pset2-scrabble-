#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points for each letter
int POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototype
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\\n");
    }
    else
    {
        printf("Tie!\\n");
    }
}

// Compute and return score for a word
int compute_score(string word)
{
    int total = 0; // 1) start score at 0

    // 2) loop through each character of the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = word[i]; // 3) look at the i-th character

        if (isalpha(c)) // 4) only score letters A–Z / a–z
        {
            c = toupper(c);         // 5) make it uppercase (so 'a' -> 'A')
            int index = c - 'A';    // 6) map 'A'..'Z' to 0..25
            total += POINTS[index]; // 7) add that letter’s points
        }
        // 8) if it's not a letter (digits, space, !, etc.), ignore it
    }

    return total; // 9) give back the total score
}
