#include <stdio.h> // library for printf and scanf
#include <math.h> // library for math functions

/*
Pseudocode:
double rad // rad input by user
double circ = 0 // initialized circumference
double area = 0 // initialized area

print -> ask for radius input
scan for radius input

calc area by pi*rad^2
calc circ by 2*pi*rad

print area and circ to 2 decimals

*/

int main(void) // still dunno but important lol
{
    double rad; // rad input by user
    double circ = 0; // initialized circumference
    double area = 0; // initialized area

    printf("Please enter the radius of the circle: "); // ask for rad input
    scanf("%lf", &rad); // scan for rad input

    area = M_PI * pow(rad, 2); // calc area
    circ = 2 * M_PI * rad; // calc circ

    printf("Your area is: %.2lf\n", area); // print area to 2 decimals
    printf("Your circumference is: %.2lf\n", circ); // print circ to 2 decimals

    return 0; // same as main(void) (dunno)
}