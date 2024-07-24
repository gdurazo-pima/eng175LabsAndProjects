#include <stdio.h> // print and scan
#include <stdbool.h> // bool
/*
Pseudocode
double age for age
bool adult for adult condition

print ask for age
scan for age

if age >= 18
    adult = true
else
    adult = false

if adult == true
    print you are an adult
if adult == false
    print you are not an adult lmaooooo

*/

int main(void)
{
    double age; // age to be inputted
    bool adult; // they want a boolean for some reason

    printf("Please enter your age: "); // asks for age
    scanf("%lf", &age); // scans age

    if(age >= 18)
    {
        adult = true;
    }
    else
    {
        adult = false;
    }

    if (adult == true)
    {
        printf("You are an adult!"); // yay
    }

    if (adult != true)
    {
        printf("You are not an adult."); // lol
    }
    


    return 0;
}