#include <stdio.h> // print and scan

/*
Pseudocode
double sum = 0 for sum
double num = 0 for number from each iteration of the sum
double lowerBound for lower bound
double upperBound for upper bound
double array[] for nums to be stored in
int i for index
int j = 0 for second index

print ask for lower and upper bounds
scan lower and upper bounds

print { for format
for i = 0; i >= lowerBounds && i <= upperBound; i++ && j++ to do the sum
    num = i * (i + 1)
    array[j] = num
    if i == upperBound
        print array[j]
    else
        print array[j], (format with comma)
    sum = sum + num

print } for format

print sum

*/

int main(void)
{
    double sum = 0; // sum
    double num = 0; // num for each iteration from sum
    double lowerBound = 0;
    double upperBound = 0;
    double array[100]; // array for nums to be stored in
    int i; // index
    int j = 0; // second index for array

    printf("Please enter a lower bound (please make the sum have 100 numbers or less): ");
    scanf("%lf", &lowerBound);
    printf("Please enter an upper bound (please make the sum have 100 numbers or less): ");
    scanf("%lf", &upperBound);

    printf("Here is the array of the sum: { "); // make the array look a little nicer
    for (i = 0; (i >= lowerBound) && (i <= upperBound); i++ && j++) // does sum from the bounds
    {
        num = i * (i + 1); // from instructions
        array[j] = num; // assigns sum to array
        sum = sum + num; // sum

        if (i == upperBound) // make it look a little nicer
        {
            printf("%lf", array[j]);
        }
        else // make it look a little nicer for the other part
        {
            printf("%lf, ", array[j]);
        }
    }
    printf(" }"); // format

    printf("\nThe sum is: %lf\n", sum);
    printf("Thank you for trying out my summation calculator!");

    return 0;
}