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












# CS50 Scrabble

![C](https://img.shields.io/badge/language-C-blue)
![CS50](https://img.shields.io/badge/CS50-Harvard-red)

## Description

A C program that calculates and compares Scrabble scores for two players. Each letter has a point value, and the program sums the points in each player's word to determine the winner.

---

## How to Compile and Run

1. Download `scrabble.c` from this repository.  
2. Open a terminal and navigate to the folder containing `scrabble.c`.  
3. Compile the program:

```bash
gcc -o scrabble scrabble.c cs50.c

Run the program:
./scrabble

Enter words for Player 1 and Player 2 when prompted.

Example
Player 1: Hello
Player 2: World
Player 1 score: 8
Player 2 score: 9
Winner: Player 2

Key Notes / Learning Outcomes

Computes Scrabble scores for words.

Handles uppercase and lowercase letters.

Determines the winner or declares a tie.

Demonstrates arrays, functions, loops, and conditionals.

Introduces string manipulation and character processing.
