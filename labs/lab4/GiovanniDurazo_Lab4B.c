#include <stdio.h> // print and scan

/*
Pseudocode
double num to be inputted
double result for result
int i for index
print ask for input
scan input
do i x num while i <= 10
print multiplication table (in do while)

*/

int main(void)
{
    double num ; // num to be inputted
    double result = 0; // initialize result
    int i = 1; // for index

    printf("Please enter a number for the multiplication table:\n");
    scanf("%lf", &num);
    
    printf("Multiplication table:\n"); // to make it look a little nicer
    
    do
    {
        result = i * num; // calcs
        printf("%d x %lf = %lf\n", i, num, result);
        i++; // adds 1 to index after you're done
    } while (i <= 10); // repeats until i = 10
    

    return 0;
}