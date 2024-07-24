#include <stdio.h> // print
#include <string.h> // strcat

/*
Pseudocode
char str1[] = i gotta say, str2[] = today was a good day for parts of the sentence
print str1 unchanged
print str2 unchanged
strcat(str1, str2) to combine
print str1 changed

*/

int main(void)
{
    
    char str1[42] = "I gotta say, "; // set up str1 (milk)
    printf("String 1: %s\n", str1); // print str1 unchanged

    char str2[69] = "today was a good day."; // set up str2 (cereal)
    printf("String 2: %s\n", str2); // print str2

    strcat(str1, str2); // combiiiine

    printf("Combined string: %s\n", str1); // print combined strings

    
    return 0;
}