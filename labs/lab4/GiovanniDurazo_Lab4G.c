#include <stdio.h> // print and scan
#include <stdlib.h> // rand

/*
Pseudocode
char plName[10], p2Name[10] for player names
int p1Choice, p2Choice for rock, paper, or scissors
int p1Score, p2Score to keep track of score
int numRounds for num of rounds
int i for index

print ask for names
scan names
print ask for num rounds
scan num rounds
print p1 vs p2 for numRounds round(s)

for i = 1; i <= numRounds; i++
    p1Choice = rand() % 3
    p2Choice = rand() % 3
    if tie
        print tie
        i-- to basically skip that round
    else if one player wins
        print they win with ___
        add 1 to their score

print p1 wins _ and p2 wins _

*/

int main(void)
{
    char p1Name[10], p2Name[10]; // for player names
    int p1Choice, p2Choice; // for rock, paper, or scissors
    int p1Score = 0; // to keep track of score
    int p2Score = 0; // to keep track of score
    int numRounds; // for num of rounds
    int i; // for index

    // rock = 0, paper = 1, scissors = 2

    printf("Please enter Player 1's name: ");
    scanf("%s", p1Name);
    printf("Please enter Player 2's name: ");
    scanf("%s", p2Name);
    printf("Please enter the number of rounds to play: ");
    scanf("%d", &numRounds);
    printf("%s v.s. %s for %d rounds\n", p1Name, p2Name, numRounds); // FIGHT!

    for (i = 1; i <= numRounds; i++) // iterates until num rounds reached
    {
        printf("Round %d:\n", i);
        p1Choice = rand() % 3; // returns 0, 1, or 2
        p2Choice = rand() % 3; // returns 0, 1, or 2

        if (p1Choice == p2Choice) // if tie
        {
            printf("It is a tie! No one wins.\n");
            i--; // makes it so the round "doesn't count"
        }
        else if ((p1Choice == 0) && (p2Choice == 1))
        {
            printf("%s wins with paper!\n", p2Name);
            p2Score++;
        }
        else if ((p1Choice == 0) && (p2Choice == 2))
        {
            printf("%s wins with rock!\n", p1Name);
            p1Score++;
        }
        else if ((p1Choice == 1) && (p2Choice == 0))
        {
            printf("%s wins with paper!\n", p1Name);
            p1Score++;
        }
        else if ((p1Choice == 1) && (p2Choice == 2))
        {
            printf("%s wins with scissors!\n", p2Name);
            p2Score++;
        }
        else if ((p1Choice == 2) && (p2Choice == 0))
        {
            printf("%s wins with rock!\n", p2Name);
            p2Score++;
        }
        else if ((p1Choice == 2) && (p2Choice == 1))
        {
            printf("%s wins with scissors!\n", p1Name);
            p1Score++;
        }
    }
    if (numRounds == 0) // just in case they say 0 rounds
    {
        printf("\nNo rounds played.");
    }
    else
    {
        printf("\n%s wins %d and %s wins %d.", p1Name, p1Score, p2Name, p2Score); // prints names and scores
    }

    printf("\nThank you for trying out my automated rock-paper-scissors game!");


    return 0;
}