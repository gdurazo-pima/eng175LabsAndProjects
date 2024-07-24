#include <stdio.h> // print and scan
#include <string.h> // strcmp

/*
Pseudocode
char userChoice[10] for operation
double num1 input
double num2 input
double result result
print ask if they wanna add, subtract, multiply, or divide
scan userChoice

if userChoice = add then add, else if userChoice = subtract then subtract, etc.
Carry out operation
Print result
else print not a valid option, sorry

*/

int main(void)
{
    char userInput[10]; // string for user input
    double num1, num2; // nums to be inputted by user
    double result = 0; // initialized calculation result

    printf("Please enter what you would like to do (add, subtract, multiply, divide):\n"); // asks
    scanf("%s", userInput);

    if (strcmp(userInput, "add") == 0)
    {
        printf("You chose: addition!\n"); // reassure them
        printf("Please enter the first number:\n");
        scanf("%lf", &num1);
        printf("Please enter the second number:\n%lf + ", num1); // format is kinda weird i know but im lazy
        scanf("%lf", &num2);

        result = num1 + num2; // calculation
        printf("%lf + %lf = %lf\nThanks for trying out my second calculator!", num1, num2, result);
    }
    else if (strcmp(userInput, "subtract") == 0)
    {
        printf("You chose: subtraction!\n"); // reassure them
        printf("Please enter the first number:\n");
        scanf("%lf", &num1);
        printf("Please enter the second number:\n%lf - ", num1); // format is kinda weird i know but im lazy
        scanf("%lf", &num2);

        result = num1 - num2; // calculation
        printf("%lf - %lf = %lf\nThanks for trying out my second calculator!", num1, num2, result);
    }
    else if (strcmp(userInput, "multiply") == 0)
    {
        printf("You chose: multiplication!\n"); // reassure them
        printf("Please enter the first number:\n");
        scanf("%lf", &num1);
        printf("Please enter the second number:\n%lf * ", num1); // format is kinda weird i know but im lazy
        scanf("%lf", &num2);

        result = num1 * num2; // calculation
        printf("%lf * %lf = %lf\nThanks for trying out my second calculator!", num1, num2, result);
    }
    else if (strcmp(userInput, "divide") == 0)
    {
        printf("You chose: division!\n"); // reassure them
        printf("Please enter the first number:\n");
        scanf("%lf", &num1);
        printf("Please enter the second number:\n%lf / ", num1); // format is kinda weird i know but im lazy
        scanf("%lf", &num2);

        result = num1 / num2; // calculation
        printf("%lf / %lf = %lf\nThanks for trying out my second calculator!", num1, num2, result);
    }
    else
    {
        printf("That was an invalid option. Please try again!");
    }

    return 0;
}