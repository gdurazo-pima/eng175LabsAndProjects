#include <stdio.h>   // print
#include <time.h>    // for seeding rand
#include <stdlib.h>  // rand
#include "hangman.h" // structs

void welcomeMessage(void)
{
    printf("Welcome, player! Are you ready to begin Hangman? Please enter 'Y' or 'N': ");
}

void adiosMessage(void)
{
    printf("See you again soon!");
}

void wordPick(char word1[9], char word2[9], char word3[9])
{
    FILE *fileptr;
    fileptr = fopen("words.txt", "r"); // opens provided words.txt file in read mode
    int i = 0;                         // index

    srand(time(NULL)); // seeds rand for true randomness
    int num = (rand() % 17) + 1;
    int num2 = (rand() % 17) + 1;
    int num3 = (rand() % 16) + 1;
    // done like this so the program doesn't accidentally read too much and leave one or more words blank

    for (i = 0; i <= num; i++) // picks first word
    {
        fscanf(fileptr, "%s", word1);
    }

    for (i = 0; i <= num2; i++) // picks second word
    {
        fscanf(fileptr, "%s", word2);
    }

    for (i = 0; i <= num3; i++) // picks third word
    {
        fscanf(fileptr, "%s", word3);
    }

    if (word1 == NULL || word2 == NULL || word3 == NULL) // check to see if the word picking was successful
    {
        printf("Sorry, there was an error in picking your three words. Please try again!");
        return; // ends program
    }

    fclose(fileptr); // closes file so the nuclear launch codes don't get leaked
}

void printInstructions(void) // i was feeling a little silly
{
    printf("\n--------------------\nThe rules are simple: You have three eight-letter words chosen at random, one for each round you will play. You need to input a letter you think might be in the\nword. If you are correct, the letter will appear in the correct spot in the word. If you are wrong, though, our hangman friend will accumulate body parts for\neach incorrect guess. Get it wrong too many times, and our friend will be lynched! You have to guess the word correctly within 6 mistakes. Repeat letters also\ncount as mistakes, so be careful! If you guess the entire word correctly, you get a point! You need two or more points to win this game.\n--------------------\n\n");
}

void printWinLose(bool win)
{
    if (win == true)
    {
        printf("Congratulations! You won (and our hangman friend lives to see another day)!\n\n");
    }

    else
    {
        printf("You lost. That's okay, though! There's always next time!\n\n");
    }
}

void printEmpty(void)
{
    printf("______\n");
    printf("|\n|\n|\n|\n");
    printf("------");
}

void printHead(void)
{
    printf("\n\n______\n");
    printf("|   O\n|\n|\n|\n");
    printf("------");
}

void printArmL(void)
{
    printf("\n\n______\n");
    printf("|   O\n|  \\\n|\n|\n");
    printf("------");
}

void printBody(void)
{
    printf("\n\n______\n");
    printf("|   O\n|  \\|\n|\n|\n");
    printf("------");
}

void printArmR(void)
{
    printf("\n\n______\n");
    printf("|   O\n|  \\|/\n|\n|\n");
    printf("------");
}

void printLegL(void)
{
    printf("\n\n______\n");
    printf("|   O\n|  \\|/\n|  /\n|\n");
    printf("------");
}

void printLegR(void)
{
    printf("\n\n______\n");
    printf("|   O\n|  \\|/\n|  / \\\n|\n");
    printf("------\n");
}