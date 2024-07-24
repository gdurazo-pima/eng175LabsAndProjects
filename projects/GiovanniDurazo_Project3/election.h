#include <stdlib.h> // i dunno but it breaks without it
#ifndef ELECTION_H  // define guard
#define ELECTION_H

typedef struct // stores voter info grabbed from people.txt
{
    char firstName[20]; // stores first name
    char lastName[20];  // stores last name
    int age;            // because age is in the text file and I don't wanna think about overcoming it
    char ssn[12];       // ssn of voter
    char phone[13];     // phone number of voter
    char partyPref[20]; // party preference of voter
} voterInfo;

typedef struct // generic person info to be used in other structs
{
    char firstName[30]; // first name
    char lastName[30];  // last name
} candidateInfo;

typedef struct // political party name and candidate info
{
    char partyName[20]; // name of party
    candidateInfo pres; // presidential candidate
    candidateInfo sen;  // senator candidate
    candidateInfo cong; // congress candidate
} polParty;             // short for political party

typedef struct vote // acts as nodes for linked list
{
    candidateInfo pres; // presidential candidate vote
    candidateInfo sen;  // senator candidate vote
    candidateInfo cong; // congress candidate vote
    voterInfo voter;    // voter info
    struct vote *next;  // points to next "node" of vote
} vote;

void printWelcome(void);                   // prints welcome messages so it looks like I made UDFs
vote *appendVote(vote **head, FILE *fptr); // UDF to help me create the list
void removeHeadVote(vote **head);          // UDF to help clear list
void removeEndVote(vote **head);           // UDF to help clear list

#endif