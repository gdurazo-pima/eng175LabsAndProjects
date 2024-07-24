#include <stdio.h> // print and scan

/*
Pseudocode
char string1[12] = "Engineering" for first string
char string2[13] = "Hello world!" for second string
int length = 0 for string length
char ptr for pointer

print string already in code

for (ptr = &string1[0]; *ptr != \\0; i++) to count until null terminator
    length++

print length

repeat for string 2

*/

int main(void)
{
    char string1[12] = "Engineering"; // first string
    char string2[13] = "Hello world!"; // second string
    int length = 0; // string length
    char *ptr; // pointer

    printf("String 1: Engineering\n");

    for (ptr = &string1[0]; *ptr != '\0'; ptr++) // runs until null terminator
    {
        length++; // increments length
    }

    printf("The length of string 1 is %d\n\n", length);

    printf("String 2: Hello world!\n");

    length = 0; // resets length so it doesn't mess up the second calculation
    
    for (ptr = &string2[0]; *ptr != '\0'; ptr++) // runs until null terminator
    {
        length++; // increments length
    }

    printf("The length of string 2 is %d", length);

    return 0;
}