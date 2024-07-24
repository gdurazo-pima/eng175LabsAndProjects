#include <stdio.h> // printf

/*
Pseudocode
double result for function at each value
double sum = 0 for total sum at the end (initialized to 0)
int i for index / x

for (i=1, i<=10, i++) to sum from 1 to 10
    result = 3i - 7
    sum = sum + result

print result

*/

int main(void)
{
    double result; // for function at each value
    double sum = 0; // initialized value for total sum
    int i; // index

    for (i = 1; i <= 10; i++)
    {
        result = 3*i - 7; // operation
        sum = sum + result; // adds results to total sum
    }

    printf("The value of the sum is: %lf.", sum);


    return 0;
}