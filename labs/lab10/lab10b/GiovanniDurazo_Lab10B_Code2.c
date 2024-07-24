#include <stdio.h> // file stuff

/*Pseudocode
open fourWordSentence
strFws to store string

fgets strFws, 18, fourWordSentence
print strFws

FCLOSE PLEASE DONT FORGET

*/

int main(void)
{
    char strFws[18]; // string to store four word sentence into
    FILE *fws = fopen("fourWordSentence.txt", "r");

    fgets(strFws, 18, fws); // gets text from file to strFws
    printf("Four word sentence from created file: %s", strFws); // prints four word sentence

    fclose(fws); // closes file


    return 0;
}