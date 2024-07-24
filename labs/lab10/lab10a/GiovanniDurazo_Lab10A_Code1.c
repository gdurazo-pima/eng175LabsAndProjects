#include <stdio.h> // file stuff

/*
Pseudocode
int a = 1, b = 0, c = -4
create file quadNums.txt and store a, b, c in quadNums.txt

*/

int main(void)
{
    int a = 1; // from assignment page
    int b = 0; // from assignment page
    int c = -4; // from assignment page

    FILE *quadNums = fopen("quadNums.txt", "w"); // creats quadNums file to store a, b, and c
    
    if (quadNums == NULL) // check to see if i broke everything
    {
        printf("Unable to create the file.");
    }
    printf("File created."); // hooray

    fprintf(quadNums, "%d\n%d\n%d", a, b, c); // prints a, b, and c values in quadNums

    fclose(quadNums); // forgot lol


    return 0;
}