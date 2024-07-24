#include <stdio.h> // print and scan
#include <math.h> // math
#include <stdbool.h> // bool for loop

/*
Pseudocode
char operator
double num1, num2 for nums to be inputted
double result = 0 for calculation
bool endLoop = false for loop

while endLoop isnt true
    print ask for operator (give options) and to cancel press anything else
    scan input

    switch(operator)
        case '+':
        print chose add
        print ask for 1st num
        scan num1
        print ask for 2nd num
        scan num2
        carry operation
        print result
        break

        case '-':
        print chose sub
        print ask for 1st num
        scan num1
        print ask for 2nd num
        scan num2
        carry operation
        print result
        break
        
        case '*':
        print chose mult
        print ask for 1st num
        scan num1
        print ask for 2nd num
        scan num2
        carry operation
        print result
        break
        
        case '/':
        print chose div
        print ask for 1st num
        scan num1
        print ask for 2nd num
        scan num2
        carry operation
        print result
        break

        default
        print canceled
        endLoop = true
        break

print thanks
    

*/

int main(void)
{
    int operator;
    double num1; // nums to be inputted
    double num2; // ditto
    double result = 0; // calculation
    bool endLoop = false; // loop

    while (endLoop != true)
    {
        printf("Please choose the operator you want to use (+ (1), - (2), * (3), / (4)) (to cancel, enter anything else): "); // ask for operator 
        scanf("%d", &operator);

        switch(operator)
        {
            case (1):
            printf("You chose: addition!\n");
            printf("Please input your first number: ");
            scanf("%lf", &num1);
            printf("Please input your second number: %lf + ", num1);
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%lf + %lf = %lf\n", num1, num2, result);
            num1; // reset
            num2; // reset
            result; // reset
            break;

            case (2):
            printf("You chose: subtraction!\n");
            printf("Please input your first number: ");
            scanf("%lf", &num1);
            printf("Please input your second number: %lf - ", num1);
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%lf - %lf = %lf\n", num1, num2, result);
            num1 = 0; // reset
            num2 = 0; // reset
            result = 0; // reset result
            break;
        
            case (3):
            printf("You chose: multiplication!\n");
            printf("Please input your first number: ");
            scanf("%lf", &num1);
            printf("Please input your second number: %lf * ", num1);
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%lf * %lf = %lf\n", num1, num2, result);
            num1 = 0; // reset
            num2 = 0; // reset
            result = 0; // reset result
            break;
        
            case (4):
            printf("You chose: division!\n");
            printf("Please input your first number: ");
            scanf("%lf", &num1);
            printf("Please input your second number: %lf / ", num1);
            scanf("%lf", &num2);
            result = num1 / num2;
            printf("%lf / %lf = %lf\n", num1, num2, result);
            num1 = 0; // reset
            num2 = 0; // reset
            result = 0; // reset result
            break;

            default:
            printf("You chose: cancel\n");
            endLoop = true;
            break;
        }
    }

printf("Thank you for trying out my simple calculator!"); // thank
    

return 0;
}