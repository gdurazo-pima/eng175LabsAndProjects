#include <stdio.h> // header
#include <math.h> // header

int main(void) // something about a main function I dunno lol
{
    double x, y, z; // variables to be inputted by the user
    double p = 0.0; // initialized perimeter
    double A = 0.0; // initialized area

    printf("Please input your x value: "); // user inputs x value
    scanf("%lf", &x); // scan inputted x value

    printf("Please input your y value: "); // user inputs y value
    scanf("%lf", &y); // scan inputted y value

    printf("Please input your z value: "); // user inputs z value
    scanf("%lf", &z); // scan inputted z value

    p = (y * 2) + (z * 2); // calculate perimeter
    A = x * (sqrt(pow(y,2)-pow(x,2))+sqrt(pow(z,2)-pow(x,2))); // calculate area

    printf("Your perimeter is: %lf\n", p); // print perimeter
    printf("Your area is: %lf\n", A); // print area


    return 0; // return 0 whatever that means
}