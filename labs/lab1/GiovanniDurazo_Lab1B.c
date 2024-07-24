#include <stdio.h>
#include <math.h>

int main(void)
{
    double l, w; // l = length, w = width
    double area = 0.0; // initialize area value

    printf("Please enter the length: ");
    scanf("%lf",&l);

    printf("Please enter the width: ");
    scanf("%lf",&w);

    area = l * w;

    printf("Your area is: %lf", area);

    return 0;
}