#include <stdio.h> // print and scan


/*Pseudocode
double newPow (double num, double power)
    returnValue = 1 to start powers
    i for index
    for i = 1; i <= power; i++
        returnValue *= num for repeated multiplication
    return returnValue

main
    num, power to be inputted
    powVal for value after exp
    printf ask for num and power
    scan num and power
    powVal = newPow(num, power)
    print powVal

*/
double newPow(double num, double power)
{
    double returnValue = 1; // sets up exponentiation
    double i; // index
    for (i = 1; i <= power; i++)
        returnValue *= num; // multiplies num by itself
    return returnValue;
}




int main(void)
{
    double num, power;
    double powVal = 0;

    printf("Please enter the number to be raised to a power: ");
    scanf("%lf", &num);
    printf("Please enter the power to raise the number to: ");
    scanf("%lf", &power);

    powVal = newPow(num, power);
    printf("%lf raised to the %lf power is %lf", num, power, powVal);


    return 0;
}