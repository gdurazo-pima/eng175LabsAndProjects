#include <stdio.h> // print and scan

/*
Pseudocode
int getQuot(int num1, int num2)
    int quot = 0
    quot = num1 / num2
    return quot

int getRem(int num1, int num2)
    int rem
    rem = num1 % num2
    return rem

main
    int num1, num2
    int quotient = 0
    int remainder = 0

    print ask for 2 nums
    scan two nums
    quotient = quot(num1, num2)
    remainder = rem(num1, num2)

    print quotient and remainder

*/

int getQuot(int num1, int num2)
{
    int quot = 0; // quotient

    quot = num1 / num2; // returns quotient bc both are integers

    return quot;
}

int getRem (int num1, int num2)
{
    int rem = 0; // remainder

    rem = num1 % num2;

    return rem;
}

int main(void)
{
    int num1, num2; // nums to be inputted by the user
    int quotient = 0;
    int remainder = 0;

    printf("Please enter your first number: ");
    scanf("%d", &num1);
    printf("Please enter your second number: ");
    scanf("%d", &num2);

    quotient = getQuot(num1, num2);
    remainder = getRem(num1, num2);
    printf("The quotient is %d and the remainder is %d", quotient, remainder);


    return 0; // hehe i know what this means now
}