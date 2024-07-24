#include <stdio.h> // print and scan

/*
Pseudocode
char c for input
print ask for input
scan assign input to c
if ascii value matches a letter, print letter
else if ascii value matches a number, print number
else print not a valid input lmao

*/

int main(void)
{
    char c;

    printf("Please enter either a letter or a number:\n"); // ask for input
    scanf("%c", &c);

    if ((c >= 97 && c < 123) || (c >= 65 && c < 91)) // if c is sandwiched between the letter ascii values (upper and lowercase)
    {
        printf("You have entered a letter!");
    }
    else if (c >= 48 && c < 58) // if c is sandwiched between the number ascii values
    {
        printf("You have entered a number!");
    }
    else // if not a letter or a number
    {
        printf("Sorry, that was not a valid input. Please try again!");
    }


    return 0;
}