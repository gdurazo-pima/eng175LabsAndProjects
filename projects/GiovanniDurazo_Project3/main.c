#include <stdio.h>    // print and scan
#include <stdbool.h>  // bool for choosing whether to start or not
#include <string.h>   // string stuff (copy and compare bc im lazy)
#include <time.h>     // seeds rand
#include "election.h" // header file

/*
Pseudocode
structs for candidate info, voter info, vote nodes, political party info
ask user for num of voters, political party names w/ candidate names, and press E to begin election
head pointer for list of votes
for i = 0; i < numVoters; i++
    make list using a form of appendNode that follows the instructions about who voters choose
count number of votes for each candidate
display who won and by how many votes

boogey on them because my last project is done

*/

int main(void)
{
    int numVotesPresA = 0;   // var to store number of votes to compare to other numVotes
    int numVotesPresB = 0;   // var to store number of votes to compare to other numVotes
    int numVotesSenA = 0;    // var to store number of votes to compare to other numVotes
    int numVotesSenB = 0;    // var to store number of votes to compare to other numVotes
    int numVotesCongA = 0;   // var to store number of votes to compare to other numVotes
    int numVotesCongB = 0;   // var to store number of votes to compare to other numVotes
    int numVoters = 0;       // user inputs number of voters
    bool endLoop = false;    // for loop asking if they wanna start the election
    char userChoice = '\0';  // var to store user choice when prompted whether to begin election or not
    vote *head = NULL;       // head pointer for vote linked list
    polParty partyA, partyB; // vars for two political parties
    vote *voteTemp;          // temp vote to manipulate
    int i;                   // index

    srand(time(NULL)); // seeds rand
    int detPp = 0;     // var to determine rand political party
    int detP = 0;      // var to determine rand pres vote
    int detS = 0;      // var to determine rand sen vote
    int detC = 0;      // var ot determine rand cong vote

    printWelcome(); // prints welcome messages
    while (!endLoop)
    {
        scanf("%d", &numVoters);

        if (numVoters < 3 || numVoters > 50)
        {
            printf("Sorry, that was outside of the available range. Please try again!\n");
            printf("Please enter the number of people who are participating in this year's MES (note that the number of voters must be between 3 and 50):\n");
        }
        else
        {
            endLoop = true; // ends the loop
        }
    }
    endLoop = false; // resets endLoop

    // this next handful of lines get political party info from the user
    printf("Alright, now I'm going to need some information about the political parties in this year's MES.\n");
    printf("Please enter the names of the political parties going against each other:\nParty A: ");
    scanf("%s", partyA.partyName);
    printf("Party B: ");
    scanf("%s", partyB.partyName);
    printf("Please don't enter the same first and last name for two or more candidates. Everyone must have a unique name!\n"); // informs user
    printf("Please enter the presidential candidate's first and last name separated by a space for the %s Party:\n", partyA.partyName);
    scanf("%s %s", partyA.pres.firstName, partyA.pres.lastName);
    printf("Please enter the presidential candidate's first and last name separated by a space for the %s Party:\n", partyB.partyName);
    scanf("%s %s", partyB.pres.firstName, partyB.pres.lastName);
    printf("Please enter the senator candidate's first and last name separated by a space for the %s Party:\n", partyA.partyName);
    scanf("%s %s", partyA.sen.firstName, partyA.sen.lastName);
    printf("Please enter the senator candidate's first and last name separated by a space for the %s Party:\n", partyB.partyName);
    scanf("%s %s", partyB.sen.firstName, partyB.sen.lastName);
    printf("Please enter the congressman candidate's first and last name separated by a space for the %s Party:\n", partyA.partyName);
    scanf("%s %s", partyA.cong.firstName, partyA.cong.lastName);
    printf("Please enter the congressman candidate's first and last name separated by a space for the %s Party:\n", partyB.partyName);
    scanf("%s %s", partyB.cong.firstName, partyB.cong.lastName);

    printf("Excellent, we have everything that we need! Please press 'E' to begin the election system!\n");

    while (!endLoop) // loops until the user inputs the right thing
    {
        scanf(" %c", &userChoice);
        if (userChoice == 'E' || userChoice == 'e') // if they input the right thing
        {
            printf("Alright, let's get this show started!\n");
            endLoop = true; // ends the loop
        }
        else
        {
            printf("Sorry, that was not a valid option. Please try again!\nAre you ready to begin this year's MES?\n"); // loop continues
        }
    }

    // deals with file stuff
    FILE *fptr;
    fptr = fopen("people.txt", "r");
    voterInfo bob; // temp voter var

    for (i = 0; i < numVoters; i++) // assigns political parties and random votes
    {
        voteTemp = appendVote(&head, fptr); // so i can modify values
        detPp = rand() % 3;                 // sets up for rand pol party selection

        // randomly assigns political party
        if (detPp == 0)
        {
            strcpy(voteTemp->voter.partyPref, partyA.partyName); // assigns voter political preference to party A
        }
        else if (detPp == 1)
        {
            strcpy(voteTemp->voter.partyPref, partyB.partyName); // assigns voter political preference to party B
        }

        // assigns voter votes in accordance to political party preference (or random if party pref remains NA)
        if (strcmp(voteTemp->voter.partyPref, partyA.partyName) == 0)
        {
            strcpy(voteTemp->pres.firstName, partyA.pres.firstName);
            strcpy(voteTemp->pres.lastName, partyA.pres.lastName);

            strcpy(voteTemp->sen.firstName, partyA.sen.firstName);
            strcpy(voteTemp->sen.lastName, partyA.sen.lastName);

            strcpy(voteTemp->cong.firstName, partyA.cong.firstName);
            strcpy(voteTemp->cong.lastName, partyA.cong.lastName);
        }
        else if (strcmp(voteTemp->voter.partyPref, partyB.partyName) == 0)
        {
            strcpy(voteTemp->pres.firstName, partyB.pres.firstName);
            strcpy(voteTemp->pres.lastName, partyB.pres.lastName);

            strcpy(voteTemp->sen.firstName, partyB.sen.firstName);
            strcpy(voteTemp->sen.lastName, partyB.sen.lastName);

            strcpy(voteTemp->cong.firstName, partyB.cong.firstName);
            strcpy(voteTemp->cong.lastName, partyB.cong.lastName);
        }
        else // when pol pref is unchanged
        {
            // sets up random condidate voting
            detP = rand() % 2;
            detS = rand() % 2;
            detC = rand() % 2;

            // randomly determines pres vote
            if (detP == 0)
            {
                strcpy(voteTemp->pres.firstName, partyA.pres.firstName);
                strcpy(voteTemp->pres.lastName, partyA.pres.lastName);
            }
            else
            {
                strcpy(voteTemp->pres.firstName, partyB.pres.firstName);
                strcpy(voteTemp->pres.lastName, partyB.pres.lastName);
            }

            // randomly determine sen vote
            if (detS == 0)
            {
                strcpy(voteTemp->sen.firstName, partyA.sen.firstName);
                strcpy(voteTemp->sen.lastName, partyA.sen.lastName);
            }
            else
            {
                strcpy(voteTemp->sen.firstName, partyB.sen.firstName);
                strcpy(voteTemp->sen.lastName, partyB.sen.lastName);
            }

            // randomly determine cong vote
            if (detC == 0)
            {
                strcpy(voteTemp->cong.firstName, partyA.cong.firstName);
                strcpy(voteTemp->cong.lastName, partyA.cong.lastName);
            }
            else
            {
                strcpy(voteTemp->cong.firstName, partyB.cong.firstName);
                strcpy(voteTemp->cong.lastName, partyB.cong.lastName);
            }
        }
        voteTemp = voteTemp->next; // moves to next vote node
    }

    printf("\nThe votes are in! Getting results...\n\n*drumroll*\n*drumroll*\n*drumroll*\n\n"); // why not

    voteTemp = head;                // temp vote pointer to count the votes
    for (i = 0; i < numVoters; i++) // counts the votes for each candidate
    {
        if ((strcmp(voteTemp->pres.firstName, partyA.pres.firstName) == 0) && (strcmp(voteTemp->pres.lastName, partyA.pres.lastName) == 0))
        {
            numVotesPresA++;
        }
        else if ((strcmp(voteTemp->pres.firstName, partyB.pres.firstName) == 0) && (strcmp(voteTemp->pres.lastName, partyB.pres.lastName) == 0))
        {
            numVotesPresB++;
        }

        if ((strcmp(voteTemp->sen.firstName, partyA.sen.firstName) == 0) && (strcmp(voteTemp->sen.lastName, partyA.sen.lastName) == 0))
        {
            numVotesSenA++;
        }
        else if ((strcmp(voteTemp->sen.firstName, partyB.sen.firstName) == 0) && (strcmp(voteTemp->sen.lastName, partyB.sen.lastName) == 0))
        {
            numVotesSenB++;
        }

        if ((strcmp(voteTemp->cong.firstName, partyA.cong.firstName) == 0) && (strcmp(voteTemp->cong.lastName, partyA.cong.lastName) == 0))
        {
            numVotesCongA++;
        }
        else if ((strcmp(voteTemp->cong.firstName, partyB.cong.firstName) == 0) && (strcmp(voteTemp->cong.lastName, partyB.cong.lastName) == 0))
        {
            numVotesCongB++;
        }

        voteTemp = voteTemp->next; // moves to next node
    }

    // the following lines determine and print the winner of each position
    // pres
    if (numVotesPresA > numVotesPresB)
    {
        printf("The presidential winner is %s %s from the %s Party! %s beat %s %s by %d votes.\n", partyA.pres.firstName, partyA.pres.lastName, partyA.partyName, partyA.pres.lastName, partyB.pres.firstName, partyB.pres.lastName, numVotesPresA - numVotesPresB);
    }
    else if (numVotesPresB > numVotesPresA)
    {
        printf("The presidential winner is %s %s from the %s Party! %s beat %s %s by %d votes.\n", partyB.pres.firstName, partyB.pres.lastName, partyB.partyName, partyB.pres.lastName, partyA.pres.firstName, partyA.pres.lastName, numVotesPresB - numVotesPresA);
    }
    else // draw case
    {
        printf("The presidential race ended in a draw between %s %s from the %s Party and %s %s from the %s Party. They both obtained %d votes each.\n", partyA.pres.firstName, partyA.pres.lastName, partyA.partyName, partyB.pres.firstName, partyB.pres.lastName, partyB.partyName, numVotesPresA);
    }

    // sen
    if (numVotesSenA > numVotesSenB)
    {
        printf("The senate winner is %s %s from the %s Party! %s beat %s %s by %d votes.\n", partyA.sen.firstName, partyA.sen.lastName, partyA.partyName, partyA.sen.lastName, partyB.sen.firstName, partyB.sen.lastName, numVotesSenA - numVotesSenB);
    }
    else if (numVotesSenB > numVotesSenA)
    {
        printf("The senate winner is %s %s from the %s Party! %s beat %s %s by %d votes.\n", partyB.sen.firstName, partyB.sen.lastName, partyB.partyName, partyB.sen.lastName, partyA.sen.firstName, partyA.sen.lastName, numVotesSenB - numVotesSenA);
    }
    else // draw case
    {
        printf("The senate race ended in a draw between %s %s from the %s Party and %s %s from the %s Party. They both obtained %d votes each.\n", partyA.sen.firstName, partyA.sen.lastName, partyA.partyName, partyB.sen.firstName, partyB.sen.lastName, partyB.partyName, numVotesSenA);
    }

    // cong
    if (numVotesCongA > numVotesCongB)
    {
        printf("The congressional winner is %s %s from the %s Party! %s beat %s %s by %d votes.\n", partyA.cong.firstName, partyA.cong.lastName, partyA.partyName, partyA.cong.lastName, partyB.cong.firstName, partyB.cong.lastName, numVotesCongA - numVotesCongB);
    }
    else if (numVotesCongB > numVotesCongA)
    {
        printf("The congressional winner is %s %s from the %s Party! %s beat %s %s by %d votes.\n", partyB.cong.firstName, partyB.cong.lastName, partyB.partyName, partyB.cong.lastName, partyA.cong.firstName, partyA.cong.lastName, numVotesCongB - numVotesCongA);
    }
    else // draw case
    {
        printf("The congressional race ended in a draw between %s %s from the %s Party and %s %s from the %s Party. They both obtained %d votes each.\n", partyA.cong.firstName, partyA.cong.lastName, partyA.partyName, partyB.cong.firstName, partyB.cong.lastName, partyB.partyName, numVotesCongA);
    }

    printf("\nThanks for using this year's MES! See you next year!"); // why not

    fclose(fptr); // close file pointer so i dont die or something

    for (i = 0; i < numVoters; i++) // frees memory so your computer doesn't blow up
    {
        removeEndVote(&head);
    }

    return 0;
}