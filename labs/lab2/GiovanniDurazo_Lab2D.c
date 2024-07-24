#include <stdio.h> // printf and scanf

/*
Pseudocode
set up string with a big enough array - 30 should be good i think
printf ask for a type of sandwich
scanf scan the string the user inputs
printf blank is a great sandwich

*/

int main(void) // yep
{
    char string[31]; // set up string
    printf("Please enter your favorite sandwich (no spaces, 30 characters max): "); // asks for sandwish type
    scanf("%s", string); // scan for string input

    printf("%s is a great sandwich!", string); // print patronizing statement


    return 0; // yeah
}