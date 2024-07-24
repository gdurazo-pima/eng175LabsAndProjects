#include <stdio.h> // print and scan

/*
Pseudocode
double array[5] for nums to be inputted
int i for index

print ask for nums

for i = 0; i < 5; i++
    scan array[i]

print array in rev
for i = 4; i >= 0; i--
    print array[i]

*/

int main(void)
{
    int array[5]; // array for inputs
    int i; // index

    printf("Please enter five integers:\n");

    for (i = 0; i < 5; i++) // to input each number sequentially
    {
        scanf("%d", &array[i]);
    }

    printf("Here are the numbers in reverse order: ");

    for (i = 4; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d", array[i]); // format stuff -> if last num print without comma
        }
        else
        {
            printf("%d, ", array[i]); // format stuff
        }
        
    }


    return 0;
}