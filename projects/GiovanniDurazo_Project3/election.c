#include <stdio.h>    // print
#include <stdlib.h>   // malloc
#include "election.h" // access to structs

void printWelcome(void)
{
    printf("Welcome to this year's Midyear Election System (MES for short)!\n");
    printf("Please enter the number of people who are participating in this year's MES (note that the number of voters must be between 3 and 50):\n");
}

vote *appendVote(vote **head, FILE *fptr)
{
    vote *temp = *head;                           // temp head variable
    vote *newVote = (vote *)malloc(sizeof(vote)); // creates new vote node
    voterInfo bob;                                // temp voter var
    newVote->voter = bob;
    fscanf(fptr, "%s %s %d %s %s %s", bob.firstName, bob.lastName, &bob.age, bob.ssn, bob.phone, bob.partyPref); // scans info from file

    if (*head == NULL) // if list is empty
    {
        *head = newVote;
        newVote->next = NULL;
    }
    else
    {
        while (temp->next) // goes through the list until the last node
        {
            temp = temp->next;
        }

        temp->next = newVote; // adds new vote node to the end of the list
        newVote->next = NULL; // makes the new last vote node point to null
    }
    return newVote;
}

void removeHeadVote(vote **head)
{
    vote *temp = *head;
    if (*head == NULL) // if empty list
    {
        printf("Ain't nothin' there to clear, pal.");
        return;
    }
    *head = temp->next; // puts temp to item the head is pointing at
    free(temp);         // frees memory
}

void removeEndVote(vote **head)
{
    vote *temp = *head; // var to move thru list
    if (*head == NULL)  // if empty list
    {
        printf("Ain't nothin' there to clear, pal.");
        return;
    }
    else if (temp->next == NULL) // if only one item in list
    {
        removeHeadVote(head);
        return;
    }

    vote *freeVote;          // var to free vote nodes
    while (temp->next->next) // looks two vote nodes ahead
    {
        temp = temp->next; // moves to last vote node in list
    }
    freeVote = temp->next; // stores vote node in freeVote
    temp->next = NULL;     // puts temp.next to NULL to "clear" the next pointer
    free(freeVote);        // frees memory
}