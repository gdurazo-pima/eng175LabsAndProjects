#include <stdio.h> // print and scan

/*
Pseudocode
double var1, var2
double *pt1 = &var1
double *pt2 = &var2

print ask for two variables
scan var1 and var2

var1 = *pt1 * 10
var2 = *pt2 * 10

print var1, var2, &var1, &var2, pt1, pt2

*/

int main(void)
{
    double var1, var2; // variables to be inputted by the user
    double *pt1 = &var1; // assigns address of var1 to pt1
    double *pt2 = &var2; // same but for var2 and pt2

    printf("Please enter variable 1: ");
    scanf("%lf", &var1);
    printf("Please enter variable 2: ");
    scanf("%lf", &var2);

    var1 = *pt1 * 10; // dereference pointer to change value at that memory location by a factor of 10
    var2 = *pt2 * 10; // dereference pointer to change value at that memory location by a factor of 10

    printf("New variable 1 = %lf, new variable 2 = %lf\n", var1, var2); // split so it's easier to read
    printf("Variable 1 has address %p\nVariable 2 has address %p\n", &var1, &var2); // print address
    printf("Pointer 1 has value %p\nPointer 2 has value %p\n", pt1, pt2); // prints value, should == above lines

    printf("Thank you for trying out my first pointer lab!"); // why not


    return 0;
}