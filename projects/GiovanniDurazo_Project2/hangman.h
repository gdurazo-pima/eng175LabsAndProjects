#ifndef HANGMAN_H // define guard
#define HANGMAN_H
#include "hangman.c"

typedef struct
{
    int gamesPlayed;  // out of three
    int points;       // need two to win
    int mistakesLeft; // reach 0 and it's game over
    char currGuess;   // current guess
} gameData;

void welcomeMessage(void);                                  // welcome message for UDF requirement
void adiosMessage(void);                                    // goodbye message for UDF req
void wordPick(char word1[9], char word2[9], char word3[9]); // randomly picks three words from the text file
void printInstructions(void);                               // why not
void printWinLose(bool win);                                // print if player won or lost

// next several are for printing hangman at various stages
void printEmpty(void);
void printHead(void);
void printArmL(void);
void printBody(void);
void printArmR(void);
void printLegL(void);
void printLegR(void);

#endif