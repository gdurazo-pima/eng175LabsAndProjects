#include <stdio.h> // print and scan

/*
Pseudocode
char userInput bc obvs
print ask for input
scan input
if userInput == a, e, i, o, u, y, A, E, I, O, U, Y
    print its a vowel
else print not a vowel

*/

int main(void)
{
    char userInput; // var for input

    printf("Please enter a letter: "); // asks for letter
    scanf("%c", &userInput);

    if(userInput == 'a')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'A')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'e')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'E')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'i')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'I')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'o')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'O')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'u')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'U')
    {
        printf("%c is a vowel!", userInput);
    }

    else if(userInput == 'y')
    {
        printf("%c is (sometimes) a vowel!", userInput);
    }

    else if(userInput == 'Y')
    {
        printf("%c is (sometimes) a vowel!", userInput);
    }

    else
    {
        printf("%c is not a vowel. Sorry!", userInput); // self explanatory
    }

    return 0;
}