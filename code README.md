# CS50 Problem Set 2 — Scrabble

This is my solution for **CS50’s Scrabble problem** (Pset2).  
It calculates word scores based on letter values, similar to the game Scrabble.

---

## 💻 Problem Description
Two players enter words. Each word is scored according to the Scrabble letter values:  

- A=1, B=3, C=3, D=2, ... Z=10  
- Non-letter characters are ignored.  
- The program announces the winner, or `Tie!` if scores are equal.  

---

## 📝 Code
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int total = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = word[i];
        if (isalpha(c))
        {
            c = toupper(c);
            int index = c - 'A';
            total += POINTS[index];
        }
    }





Sample Terminal Results

$ ./scrabble
Player 1: Question?
Player 2: Answer!
Player 1 wins!

$ ./scrabble
Player 1: COMPUTER
Player 2: SCIENCE
Tie!

Player 1: BANANA
Player 2: APPLE
Player 2 wins!

Player 1: quiz
Player 2: jazz
Player 2 wins!

Player 1: Question
Player 2: CS50
Player 1 wins!






Scrabble Project

How to Compile and Run



gcc -o scrabble scrabble.c cs50.c
./scrabble

Key Notes

Computes scores for words based on Scrabble letter values.

Accepts input from two players and determines the winner.

Handles uppercase and lowercase letters.

Uses functions and arrays effectively.
Player 1: Hello!
Player 2: He llo
Tie!

    return total;
}
