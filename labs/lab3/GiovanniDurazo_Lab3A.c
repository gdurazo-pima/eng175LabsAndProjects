#include <stdio.h> // printf and scanf
#include <math.h> // math

/*
Pseudocode
num = 987
if num % 2 == 0, print even
else print odd


*/

int main(void) // impt
{
    int n = 987; // num chosen

    printf("The number is: %d.\n", n); // print number being tested

    if((n % 2) == 0) // if it's even
    {
        printf("The number is even."); // print even
    }
    else // if not
    {
        printf("The number is odd."); // print odd
    }

    return 0; // yeah
}