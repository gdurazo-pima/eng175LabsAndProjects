#include <stdio.h>   // print, scan
#include <stdlib.h>  // rand to grab words
#include <stdbool.h> // loop and win condition
#include <string.h>  // strcmp and strcpy
#include <time.h>    // seeding the rand function
#include "hangman.h" // header file with hangman stuff

/*
Pseudocode
UDFs: welcome, goodbye, word picker, winLose message, print hangman
struct: game data (games played, points/games won, mistakes made, current guess)
all inside loop to keep asking if they wanna play
ask and scan if ready to begin
randomly pick word from list using rand and store in array
"word is _ _ _ _ _ _ _ _" and print empty hangman stand
ask and scan user input
if correct letter, input letter in correct place
if not, add hangman limb and decrease mistake counter (if 0, round over)
if get all letters, yippee hangman doesn't die and add to point counter
if run out of tries before finish word, womp womp hangman dies
repeat twice more so put inside for loop
if win count >= 2, print you won; else, you lost
ask if wanna play again
repeat whole thing

*/

int main(void)
{
    bool endLoop = false;            // to end loop
    char chooseCont;                 // for player choice to start and continue
    bool loopTemp = false;           // for loop asking if they want to continue after each round
    bool loopTemp2 = false;          // for other loop asking if they wanna continue after each game
    bool win = false;                // to see if the player wins the round, initialized because why not
    char tempWord[9] = {"________"}; // to compare currWord to
    char currWord[9] = {"________"}; // placeholder for current word
    int i;                           // index
    int j;                           // index for round number
    gameData thisGame;               // declare var to store game data

    // dynamically allocate three words to play with and store in array
    char *word1 = (char *)malloc(9 * sizeof(char));
    char *word2 = (char *)malloc(9 * sizeof(char));
    char *word3 = (char *)malloc(9 * sizeof(char));
    char *array[3] = {word1, word2, word3}; // stores words in array because that's a requirement
    char wordTemp[9];                       // temp var to access letters when checking the player's guess

    welcomeMessage(); // welcomes player

    scanf("%c", &chooseCont);
    if (chooseCont == 'Y' || chooseCont == 'y') // if the player wants to play
    {
        printf("Then let's start!\n");
        printf("Picking your three words...\n");
        printInstructions(); // prints game instructions
        printf("Alright, let's get to playing!\n");

        while (endLoop == false) // for each game
        {
            loopTemp2 = false;   // so we can keep asking if they wanna play another game
            thisGame.points = 0; // resets points for each game

            wordPick(word1, word2, word3); // picks three words from words.txt at random

            for (j = 0; j < 3; j++) // for each round
            {
                loopTemp = false;          // so we can enter the exit choice again
                thisGame.mistakesLeft = 6; // resets mistakes at the start of each round
                thisGame.currGuess = 0;    // resets current guess at the start of each round

                strcpy(currWord, "________"); // resets currWord

                printf("\nBegin round %d!", j + 1);                                                                          // indicate round number
                printf("\nYou have %d point(s). You need %d more point(s) to win.\n", thisGame.points, 2 - thisGame.points); // indicates current points

                strcpy(wordTemp, array[j]); // copies word in array to wordTemp so i can access its letters bc i don't know how to otherwise

                printEmpty();                                                         // prints empty stand
                printf("\nHere is your word: %s\nPlease enter a guess:\n", currWord); // prints underscores

                while (thisGame.mistakesLeft != 0) // exits once the player doesn't have any more mistakes left (calculates inside this loop)
                {
                    strcpy(tempWord, currWord); // makes tempWord = currWord for later comparison

                    scanf(" %c", &thisGame.currGuess);

                    for (i = 0; i < 8; i++) // letter check
                    {
                        if (thisGame.currGuess == wordTemp[i]) // if the letter exists in the word
                        {
                            printf("%c is in the word!\n", thisGame.currGuess); // lets the player know they got a correct letter
                            currWord[i] = thisGame.currGuess;                   // puts letter in correct place
                        }
                    }

                    if (strcmp(currWord, wordTemp) == 0) // if you got all letters correct
                    {
                        printf("\nYou guessed all the correct letters in %s! Let's go to the next round!\n\n", wordTemp); // says full word bc why not
                        thisGame.points++;                                                                                // adds 1 point
                        break;                                                                                            // ends current while loop
                    }

                    if (strcmp(currWord, tempWord) == 0) // if currWord is the same after letter check i.e. letter wasn't there
                    {
                        thisGame.mistakesLeft--; // reduces mistakes left by 1
                        printf("Sorry, %c is not in the word. Try again!\n", thisGame.currGuess);
                    }

                    switch (thisGame.mistakesLeft) // figures out which stand to print based on current mistakes remaining
                    {
                    case 6:
                        printEmpty();
                        printf("\nHere is your word: %s. You have %d mistakes remaining.\nPlease enter a guess:\n", currWord, thisGame.mistakesLeft);
                        break;

                    case 5:
                        printHead();
                        printf("\nHere is your word: %s. You have %d mistakes remaining.\nPlease enter a guess:\n", currWord, thisGame.mistakesLeft);
                        break;

                    case 4:
                        printArmL();
                        printf("\nHere is your word: %s. You have %d mistakes remaining.\nPlease enter a guess:\n", currWord, thisGame.mistakesLeft);
                        break;

                    case 3:
                        printBody();
                        printf("\nHere is your word: %s. You have %d mistakes remaining.\nPlease enter a guess:\n", currWord, thisGame.mistakesLeft);
                        break;

                    case 2:
                        printArmR();
                        printf("\nHere is your word: %s. You have %d mistakes remaining.\nPlease enter a guess:\n", currWord, thisGame.mistakesLeft);
                        break;

                    case 1:
                        printLegL();
                        printf("\nHere is your word: %s. You have %d mistakes remaining.\nPlease enter a guess:\n", currWord, thisGame.mistakesLeft);
                        break;

                    default: // no mistakes left
                        printLegR();
                        printf("You have no mistakes remaining. The word is %s. You lose this round. Better luck next time!\n", wordTemp); // says full word bc why not
                        break;
                    }
                }
                while (loopTemp == false) // ask if they wanna continue after each round
                {
                    printf("Would you like to continue playing? Please enter 'Y' or 'N': ");
                    scanf(" %c", &chooseCont);
                    if (chooseCont == 'Y' || chooseCont == 'y')
                    {
                        printf("Let's continue!\n");
                        loopTemp = true; // ends current continue prompt loop
                    }
                    else if (chooseCont == 'N' || chooseCont == 'n')
                    {
                        printf("Hope you had fun!\n");
                        endLoop = true;   // ends overall loop
                        loopTemp = true;  // ends current continue prompt loop
                        loopTemp2 = true; // skips game continue prompt
                        j += 3;           // adds rounds so round loop doesn't continue
                    }
                    else
                    {
                        printf("Sorry, that was an invalid input. Please try again!\n");
                        continue; // asks current continue prompt again
                    }
                }
            }

            // point check
            if (thisGame.points >= 2) // if the player wins at least two rounds, as per the instructions
            {
                win = true;
            }
            else
            {
                win = false; // reassigns win = false just to be safe
            }

            printf("\nYou ended this game with %d point(s). ", thisGame.points); // tell the player how many points they ended with
            printWinLose(win);                                                   // prints correct message depending on if the player won or lost

            while (loopTemp2 == false) // ask if they wanna continue after each game
            {
                printf("Would you like to play another game? Please enter 'Y' or 'N': ");
                scanf(" %c", &chooseCont);
                if (chooseCont == 'Y' || chooseCont == 'y')
                {
                    printf("Back on the saddle we go!\n");
                    loopTemp2 = true; // ends current continue prompt
                }
                else if (chooseCont == 'N' || chooseCont == 'n')
                {
                    printf("Sounds good! Hope you had fun!\n");
                    endLoop = true;   // ends overall loop
                    loopTemp2 = true; // ends current continue prompt
                }
                else
                {
                    printf("Sorry, that was an invalid input. Please try again!\n");
                    continue; // continues current continue prompt
                }
            }
        }
    }

    else if (chooseCont == 'N' || chooseCont == 'n') // message stuff
    {
        printf("Aww, that's a shame. Maybe next time!\n");
    }
    else
    {
        printf("That was not a valid input. I assume you don't want to play, then. That's okay!\n");
    }

    adiosMessage(); // says bye bye

    free(word1); // frees dynamically allocated words at beginning so the world doesn't explode or something i dunno
    free(word2); // ''
    free(word3); // ''

    return 0;
}