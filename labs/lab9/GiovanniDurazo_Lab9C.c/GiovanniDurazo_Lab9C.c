#include <stdio.h> // print, file reading
#include "person.h" // header file with structures

/*
Pseudocode

read file for person info and store in corresponding areas in person structure
store structures in an array
use if else statements and logic to print people who meet the criteria
*/

int main(void)
{
    FILE *personPtr; // pointer to text file
    personPtr = fopen("Lab9C.txt", "r"); // opens text file in read more
    person peep; // person variable
    char temp; // temp variable for printing
    int i; // index
    person array[10]; // array of people as asked by instructions

    for (i = 0; i < 10; i ++) // grabs each person's info and puts them in the array
    {
        fscanf(personPtr, "%s %s %d %d %c %s", peep.firstName, peep.lastName, &peep.age, &peep.income, &peep.married, peep.state);
        array[i] = peep;
    }
    
    for (i = 0; i < 10; i ++) // checks to see if person meets the conditions specified by the assignment instructions
    {
        if (array[i].age > 21) // biggest limiting condition says only consider them if they're over 21, not 21+
        {
            if (array[i].state == "CA") // if from california
            {
                if (array[i].married == 'Y') // if married
                {
                    if (array[i].income >= 150000)
                    {
                        printf("Reach out to %s %s from %s, who is %d years old.\n", array[i].firstName, array[i].lastName, array[i].state, array[i].age); // yippee
                    }
                }

                else // if not married
                {
                    if (array[i].income >= 80000)
                    {
                        printf("Reach out to %s %s from %s, who is %d years old.\n", array[i].firstName, array[i].lastName, array[i].state, array[i].age); // yippee
                    }
                }
            }

            else // if not from california
            {
                if (array[i].married == 'Y') // if married
                {
                    if (array[i].income >= 100000)
                    {
                        printf("Reach out to %s %s from %s, who is %d years old.\n", array[i].firstName, array[i].lastName, array[i].state, array[i].age); // yippee
                    }
                }

                else // if not married
                {
                    if (array[i].income >= 60000)
                    {
                        printf("Reach out to %s %s from %s, who is %d years old.\n", array[i].firstName, array[i].lastName, array[i].state, array[i].age); // yippee
                    }
                }
            }
        }
    }

    fclose(personPtr); // close file


    return 0;
}