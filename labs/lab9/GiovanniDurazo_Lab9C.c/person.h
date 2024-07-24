#ifndef PERSON_H // define guard thing
#define PERSON_H

typedef struct // structure to store ppl info
{
    char firstName[7];
    char lastName[10];
    int age;
    int income;
    char married;
    char state[3];
} person;

#endif