#include <stdio.h> // print and scan
#include <math.h> // pow

/*
Pseudocode
int num for inputted number
int sum = 0 for sum
int digit = 0 for digit
int i for index
int mag for mag

print ask for num
scan num

for run until no more digits to get
    mag = pow(10, i) bc im lazy
    digit = ((num % mag) - sum) / (mag / 10) to get numbers from correct number places without extra stuff
    sum = sum + digit

print sum

*/

int main(void)
{
    int num; // num to be inputted
    int sum = 0;
    int digit = -1; // digit to be added
    int i; // index
    int mag; // so I do not type pow(10, i) bc I'm lazy lol (mag is short for magnitude)

    printf("Please enter your number (must be a positive integer): ");
    scanf("%d", &num);


    for (i = 1; digit != 0; i++) // runs until there are no more digits to get
    {
        mag = (int)pow(10, i); // dont wanna keep typing it
        digit = ((num % mag) - sum) / (mag / 10); // gets digit from correct place as a single number minus prev nums
        sum = sum + digit; // yeah
    }
    printf("The sum of the digits in %d is: %d\n", num, sum);


    return 0; // you dont wanna know how long this took me lol
}