#include <stdio.h> // print and scan

/*
Pseudocode
void elemPrint(elem1, elem2)
    print elem1 and elem2

main
    arr[4] = 2, 8, 4, 12
    elem1 = arr[1]
    elem2 = arr[2]
    print array
    elemPick(elem1, elem2)

*/

void elemPrint(int elem1, int elem2);

int main(void)
{
    int arr[4] = {2, 8, 4, 12}; // given ages
    int elem1 = arr[1]; // second array element
    int elem2 = arr[2]; // third array element
    int i; // index

    printf("Given ages:\n{ ");

    for (i = 0; i < 4; i++) // prints array
    {
        if (i == 3) // format stuff
        {
            printf("%d", arr[i]);
        }

        else
        {
            printf("%d, ", arr[i]);
        }
    }
    printf(" }\n"); // format stuff

    elemPrint(elem1, elem2);


    return 0;
}

void elemPrint(int elem1, int elem2) // UDF to print second and third elements
{
    printf("The second and third elements of the array are %d and %d, respectively", elem1, elem2);
}