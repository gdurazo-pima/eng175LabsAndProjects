#include <stdio.h> // print and scan
#include <math.h> // pow

/*
Pseudocode
int num to be entered
int i for index
int sum = 0 for 9 sum
int temp = 0 for loop
print enter num
scan num
for i = 1; i <= num; i++
    temp = 9 * pow(10, i - 1)
    sum = sum + temp

    if i == num
        print sum
    else print sum +

*/

int main(void)
{
    int num; // to be inputted
    int sum = 0; // for sum
    int i; // index
    int temp = 0; // temp for loop

    printf("Please enter a positive integer number: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        temp = 9 * pow(10, i - 1); // gets the 9 values
        sum = sum + temp; // adds 9s so we get repeating 9s instead of 90, 900, etc.

        if (i == num) // formatting stuff so it ends without an extra "+"
        {
            printf("%d", sum);
        }
        else
        {
            printf("%d + ", sum);
        }
        
    }
    if (num == 0)
    {
        printf("No output");
    }

    return 0;
}