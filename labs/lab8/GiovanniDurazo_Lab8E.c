#include <stdio.h> // print and scan

/*
Pseudocode
double elemSum(array[6])
    double sum = 0 for sum
    int i for index
    for i = 0; i < 6; i++
        sum += array[i]
    return sum

main
    array[6] = 23.4, 55, 22.6, 3, 40.5, 18
    print elemSum


*/

double elemSum(double arr[6]);

int main(void)
{
    double arr[6] = {23.4, 55, 22.6, 3, 40.5, 18}; // given array
    double sum = elemSum(arr);
    int i; // index

    printf("The elements of the array are:\n{ ");
    for (i = 0; i < 6; i++) // prints array elements
    {
        if (i == 5) // format stuff
        {
            printf("%.1lf", arr[i]);
        }
        else
        {
            printf("%.1lf, ", arr[i]);
        }
    }
    printf(" }\n"); // format stuff

    printf("The sum of the elements of the array is %.1lf", sum);


    return 0;
}

double elemSum(double arr[6])
{
    double sum = 0; // initialized sum of elements
    int i; // index

    for (i = 0; i < 6; i++) // sums elements
    {
        sum += arr[i];
    }

    return sum; // returns sum
}