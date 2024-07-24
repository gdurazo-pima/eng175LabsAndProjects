#include <stdio.h> // print and scan
#include <math.h> // math stuff
#include <stdbool.h> // for bool for loops

/*
Pseudocode
double T(final temp,initialized), t_s(env temp), d(initial temp difference), k(cooling constant), t(time in mins)
int item for input
int exit = 0 for exit
bool endLoop = false

while endLoop isnt true:

    printf ask for input (give options)
    scanf for input

    if item == 1 = coffee define var for coffee
    if item == 2 = soup define var for soup
    if item == 3 = engine define var for engine
    else var are all 0 and print sorry
    

    printf ask for time
    scanf for input

    math for T

    print T

    printf press 1 to exit loop
    scanf for exit var assignment
    if exit == 1, endLoop = true


*/

int main(void) // impt
{
    double t_s, d, k, t; // env temp, inital temp difference, cooling constant, time in mins
    double T = 0; // initialized final temp
    int item; // item to be inputted (of three presented options)
    int exit = 0; // exit var for loop
    bool endLoop = false; // for loop

    while (endLoop != true) // loop until endLoop is true, defiens var depending on user input
    {
        printf("Please select an option (coffee = 1, soup = 2, engine = 3): "); // print for options
        scanf("%d", &item); // scan for input

        if (item == 1)
        {
            printf("You have selected: coffee\n");
            t_s = 70;
            d = 130;
            k = 0.4856;
        } 
        else if (item == 2)
        {
            printf("You have selected: soup\n");
            t_s = 65;
            d = 145;
            k = 0.05;
        }
        else if (item == 3)
        {
            printf("You have selected: engine\n");
            t_s = 60;
            d = 130;
            k = 0.0341;
        }
        else
        {
            printf("Sorry! That was not a valid input.\n"); // lmao
            t_s = 0;
            d = 0;
            k = 0;
        }

        printf("Please enter a time in minutes: ");
        scanf("%lf", &t); // defines time

        T = t_s + d * exp((-k) * t); // equation

        printf("After %lf minutes, the final temperature is: %.2lf degrees Fahrenheit.\n", t, T); // solution

        printf("Enter 1 to cancel, or enter another number to continue: ");
        scanf("%d", &exit);

        if (exit == 1)
        {
            endLoop = true; // stops loop
        }

    }
    printf("Thank you for trying out my code!"); // thanks
    return 0; // impt
}