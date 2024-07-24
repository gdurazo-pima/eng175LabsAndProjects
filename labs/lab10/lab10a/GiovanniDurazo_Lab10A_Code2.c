#include <stdio.h> // file stuff, print
#include <math.h> // sqrt and pow

/*
Pseudocode
int a, b, c, zero = 0 for calcs
get a, b, c values from quadNums
use quad formula to calc zeroes
print zeroes

*/

int main(void)
{
    int a, b, c; // from quadNums
    double zero = 0; // to be calculated
    FILE *inputFile = fopen("quadNums.txt", "r"); // opens quadNums

    fscanf(inputFile, "%d %d %d", &a, &b, &c); // assigns values from quadNums to a, b, and c
    printf("a = %d\nb = %d\nc = %d\n\n", a, b, c); // check values

    zero = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 2 * a; // calcs first root
    printf("The first zero is %lf\n", zero);
    zero = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 2 * a; // calcs second root
    printf("The second zero is %lf", zero);

    fclose(inputFile); // forgot lol


    return 0;
}