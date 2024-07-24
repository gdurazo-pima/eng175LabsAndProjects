#include <stdio.h> // print and scan
#include <stdlib.h> // malloc and rand

/*
Pseudocode
void tempCalcs(double *ptr, int size)
    double maxTemp = minTemp = avgTemp = avg = 0
    int i for index
    loop through array, comparing values with each other
        if ptr[i] < ptr[i - 1], new minTemp
        similar for maxTemp but if ptr[i] > ptr[i - 1]
        avg += ptr[i]
    avgTemp = avg / size
    print results

main
    double *ptr, int size, i = 0 for index
    print ask for size
    scan size
    ptr = (double *)malloc(size * sizeof(double))
        check if enough memory w null pointer
    while i < size
        ptr[i] = i + 1
            make sure it doesn't go over 120
        i++
    print array
    tempCalcs(ptr, size)

*/

void tempCalcs(double *ptr, int size); // max, min, avg temp

int main(void)
{
    double *ptr; // pointer for dynamic memory allocation (DMA)
    int size = 0; // size of array
    int i = 0; // index

    printf("Please enter the desired size of the array: ");
    scanf("%d", &size);

    ptr = (double *)malloc(size * sizeof(double)); // allocates memory
        if (ptr == NULL) // if it's too big lmao
        {
            printf("There was an error allocating the proper memory. Please try again.");
        }
    
    while (i < size)
    {
        ptr[i] = i + 1; // stores incremental values in the array (for the test case)

        if (ptr[i] > 5) // following values start from 0 after text case
        {
            ptr[i] = rand() % 121; // randomly returns values b/t 0 and 120 bc why not lmao
        }

        i++; // we could've also used a nice for loop
    }

    printf("Here is the resulting temperature array:\n{ ");
    for (i = 0; i < size; i++) // prints array
    {
        if (i == (size - 1)) // format stuff
        {
            printf("%lf ", ptr[i]);
        }

        else // format stuff
        {
            printf("%lf, ", ptr[i]);
        }
    }
    printf("}\n\n"); // format stuff

    tempCalcs(ptr, size); // does max, min, avg temp stuff
    free(ptr); // because i am a responible coder and definitely didn't forget this before trying to first run


    return 0;
}

void tempCalcs(double *ptr, int size)
{
    double maxTemp = 0;
    double minTemp = ptr[0]; // starts at 1st elements bc things don't work otherwise
    double avgTemp = 0;
    double avg = 0; // temp average variable for avgTemp calcs
    int i; // index

    for (i = 0; i < size; i++) // goes through array
    {
        if (ptr[i] > ptr[i - 1]) // if value is greater than preceeding
        {
            maxTemp = ptr[i];
        }
        else if (ptr[i] < ptr[i - 1]) // if value is less than preceeding
        {
            minTemp = ptr[i];
        }

        avg += ptr[i]; // gets avgTemp calc ready
    }

    avgTemp = avg / size;

    printf("The maximum temperature is %lf degrees Fahrenheit\n", maxTemp);
    printf("The minimum temperature is %lf degrees Fahrenheit\n", minTemp);
    printf("The average temperature is %lf degrees Fahrenheit\n", avgTemp);
}