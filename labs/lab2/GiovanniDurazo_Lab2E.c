#include <stdio.h> // print and scan
#include <stdlib.h> // rand

/*
Pseudocode
int die1, die2, numRoll
int diceSum = 0
int i for index

print ask for numRoll
scan for numRoll

for (i = 1; i == numRoll; i++)
    die1 = rand % 6 + 1 to gen nums 1-6
    die2 = rand % 6 + 1 to gen nums 1-6
    diceSum = die1 + die 2
    print die1, die2, diceSum, dice roll i

*/

int main(void)
{
    int die1, die2, numRoll; // die1 is 1st die1, die2 is 2nd die, numRoll is inputted
    int diceSum = 0; // dice sum
    int i; // index

    printf("Please enter the number of times you want to roll the dice: ");
    scanf("%d", &numRoll);

    for (i = 1; i <= numRoll; i++) // loops until it iterates as many times as requested
    {
        die1 = (rand() % 6) + 1; // gets nums 1-6
        die2 = (rand() % 6) + 1; // gets nums 1-6
        diceSum = die1 + die2; // nuff said

        printf("Dice roll %d:\nDie 1: %d\nDie 2: %d\nSum of Dice: %d\n\n", i, die1, die2, diceSum); // prints table
    }


    return 0;
}