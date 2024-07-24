#include <stdio.h> // print and scan

/*
Pseudocode
int array[5] = {1, 2, 3, 4, 5}
int *ptr for pointer to be used later
int i for index
int sum = 0 for sum

print array using for loops

for i = 0; i < 5; i++
    ptr = &array[i]
    print "address of element i = ptr"
    sum = sum + *ptr

print sum

*/

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5}; // array to be added
    int *ptr; // pointer to be used later
    int i; // index
    int sum = 0; // initialized sum

    printf("Here is the array whose elements will be added together:\n{ ");
    for (i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            printf("%d ", array[i]); // format stuff
        }
        else
        {
            printf("%d, ", array[i]); // format stuff
        }
    }
    printf("}\n"); // format stuff

    for (i = 0; i < 5; i++)
    {
        ptr = &array[i]; // assigns ptr to element address
        printf("The memory location of element %d is %p\n", i + 1, ptr);
        sum += *ptr; // sums elements using pointer dereference
    }

    printf("The sum of the array's elements is %d", sum);


    return 0;
}