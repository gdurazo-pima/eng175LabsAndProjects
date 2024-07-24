#include <stdio.h> // print, file stuff

/*
Pseudocode
make file fourWordSentence
print words to be stored
store words in fourWordSentence
DON'T FORGET FCLOSE FOR THE LOVE OF EVERYTHING THAT IS HOLY (lol)

*/

int main(void)
{
    char fws[18] = "It sucks to suck."; // four word sentence
    FILE *ftemp = fopen("fourWordSentence.txt", "w"); // opens fourWordSentence in write mode

    if (ftemp == NULL) // check to see if i broke everything
    {
        printf("Unable to create the file.\n\n"); // womp womp
        return -1; // guess this ends the program early
    }
    printf("File created.\n\n"); // yippee

    fprintf(ftemp, "%s", fws); // prints four word sentence in fourWordSentence

    fclose(ftemp); // i dunno why but i have to


    return 0;
}