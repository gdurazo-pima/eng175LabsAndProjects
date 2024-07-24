#include <stdio.h> // print and scan

/*
Pseudocode
int num, i, j for number to be inputted (dimensions of square) and two indices
print ask for dimensions of square
scan num
do
    do
        print width of square
        i++
    while i is <= num

    print \n for height of square
    j++
while j <= num

*/

int main(void)
{
    int num; // to be inputted
    int i = 0; // index
    int j = 0; // second index

    printf("Enter the height and width of the square (must be a positive integer): ");
    scanf("%d", &num);

    do
    {
        do
        {
            printf("#"); // width of square
            i++;
        } while (i <= (num - 1));
        printf("\n"); // print height
        i = 0; // resets index so it can print the width at the new height
        j++; // secondary index so things don't break (don't ask lol)
    } while (j <= (num - 1));


    return 0;
}