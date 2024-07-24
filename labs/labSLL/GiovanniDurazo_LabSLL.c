#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
Pseudocode:
print reverse
    node *temp = head
    int array[5] to store data
    int i = 0
    if empty, print empty
    while temp != NULL
        array[i].data = temp->data
        temp = temp->next
        i++
    print in reverse

reverse list
    manipulate pointers so head always points to the first node and current chugs along until it reaches the end like how Sahachel explained

find middle
    find middle node, then print data

delete middle
    find middle node, link node before middle to node after middle, delete middle

*/

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

bool nodeExist(int data, Node **head);
void appendNode(int data, Node **head);
void printList(Node *head);
void printListReverse(Node *head);
void reverseLinkedList(Node **head);
void findMiddleNode(Node *head);
void deleteMiddleNode(Node *head);

int main(void)
{
    Node *head = NULL;

    // Test list 1
    appendNode(1, &head);
    appendNode(2, &head);
    appendNode(3, &head);
    appendNode(4, &head);
    appendNode(5, &head);
    printf("Normal list printed:\n"); // why not
    printList(head);

    // Calling function1 : expect printing 5->4->3->2->1->->NULL
    printf("\nNormal list reverse printed:\n"); // why not
    printListReverse(head);

    // Calling function2
    reverseLinkedList(&head);
    printf("\nReverse list printed:\n"); // why not
    printList(head);                     // expect 5->4->3->2->1->->NULL

    head = NULL;          // empties list
    appendNode(1, &head); // refills list
    appendNode(2, &head); // ''
    appendNode(3, &head); // ''
    appendNode(4, &head); // ''
    appendNode(5, &head); // ''

    // function3
    printf("\n");         // nicer to look at
    findMiddleNode(head); // Output: "middle node is 3"

    // function4:
    deleteMiddleNode(head); // input: 1->2->3->4->5->->NULL
    printList(head);        // output (by printList(head4)): 1->2->4->5->->NULL
    printf("\n");           // nicer to look at

    // Test list 2
    Node *head2 = NULL;
    appendNode(21, &head2);
    appendNode(44, &head2);
    appendNode(32, &head2);
    appendNode(45, &head2);
    appendNode(5, &head2);
    appendNode(25, &head2);

    // function3
    // input: 21->44->32->45->5->25->NULL
    findMiddleNode(head2); // Output: "middle node is 45"

    // function4:
    deleteMiddleNode(head2); // input: 21->44->32->45->5->25->NULL
    printList(head2);        // output (by printList(head4)): 21->44->32->5->25->NULL
    printf("\n");            // nicer to look at

    // Test list 3
    Node *head3 = NULL;
    appendNode(1, &head3);
    appendNode(94, &head3);
    appendNode(37, &head3);
    appendNode(4, &head3);
    appendNode(45, &head3);
    appendNode(58, &head3);

    // function 3
    // input: 1->94->37->4->45->58->NULL
    findMiddleNode(head3); // Output: "middle node is 37"

    // function4:
    deleteMiddleNode(head3); // input: 1->94->37->4->45->58->NULL
    printList(head3);        // output (by printList(head4)): 1->94->4->45->58->NULL

    printf("\nAnd that is my last lab!");

    return 0;
}

/*
    This is a helper function which will help us
    determine if a node exist in the list
*/
bool nodeExist(int data, Node **head)
{
    // setting temp = to the first element of the list
    Node *temp = *head;

    while (temp != NULL)
    {
        if (data == temp->data)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

void appendNode(int data, Node **head)
{

    if (nodeExist(data, head))
    {
        printf("This node already exist in the list\n");
        return;
    }

    // Create a new node using dynamic memory allocation
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *temp = *head;

    // Case 1: Empty list
    if (*head == NULL)
    {
        /*
            before: head -> NULL
        */
        *head = newNode;
        newNode->next = NULL;
        /*               (data, next)
            after: head -> NewNode -> NULL
        */
    }
    else
    {
        /*

         supposed we want to add node (20): want this (51)->(7)->(4)->(20)->NULL
                    temp
         (51)->(7)->(4)->(new)->NULL
        */
        // Case2: List is not empty
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

// This function prints the linkedlist
void printList(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("->NULL\n");
}

void printListReverse(Node *head)
{
    Node *temp = head; // temp node ptr
    Node dataArr[5];   // array to put node data in
    int i = 0;         // index

    if (head == NULL) // if empty list
    {
        printf("The list is empty.");
        return; // ends program early
    }

    while (temp != NULL) // assigns data to array
    {
        dataArr[i].data = temp->data; // puts current data into array
        temp = temp->next;            // moves to next node
        i++;                          // increments index for data assignment
    }

    for (i = 4; i >= 0; i--) // prints array in reverse
    {
        printf("%d->", dataArr[i].data);
    }
    printf("->NULL\n"); // prints null ptr
}

void reverseLinkedList(Node **head)
{
    Node *temp = *head;   // current node pointer
    Node *newHead = temp; // temp head pointer for new list
    Node *ptrHold;        // var to hold node pointers

    if (head == NULL) // if empty list
    {
        printf("The list is empty.");
        return; // ends program early
    }

    while (temp->next != NULL)
    {
        ptrHold = temp->next->next; // holds ptr so list doesn't get lost
        temp->next->next = newHead; // puts new head as one ahead of current
        newHead = temp->next;       // makes new head the one in front of temp to get reverse ordering right
        temp->next = ptrHold;       // puts current node in correct position
    }
    temp->next = NULL; // makes last node point to null

    *head = newHead; // assigns list to original head
}

void findMiddleNode(Node *head)
{
    Node *temp = head; // temp node
    int pos = 0;       // position of node in list
    int mid = 0;       // var for middle position of list
    int midRem = 0;    // var for remainder of pos % 2
    int i;             // index for going through list
    int data1, data2;  // var to hold two mid vals for even-numbered list to compare

    if (head == NULL) // if empty list
    {
        printf("The list is empty.");
        return; // ends program early
    }

    while (temp) // counts number of nodes
    {
        temp = temp->next;
        pos++;
    }
    temp = head; // resets temp to head

    mid = pos / 2;    // gets middle
    midRem = pos % 2; // to see if list has an even or odd number of elements
    if (midRem == 1)  // in the case of an odd-numbered list
    {
        for (i = 0; i < mid; i++)
        {
            temp = temp->next; // moves to middle node
        }
        printf("The middle node is %d\n", temp->data);
    }
    else // when list has an even number of items
    {
        for (i = 1; i < mid; i++)
        {
            temp = temp->next; // moves to "left middle"
        }
        data1 = temp->data; // assigns "left middle" to data1
        temp = head;        // resets temp to head

        for (i = 1; i <= mid; i++)
        {
            temp = temp->next; // moves to "right middle"
        }
        data2 = temp->data; // assigns "right middle" to data2

        if (data1 > data2) // prints greater of two values
        {
            printf("The middle node is %d\n", data1);
        }
        else // prints greater of two values
        {
            printf("The middle node is %d\n", data2);
        }
    }
}

void deleteMiddleNode(Node *head)
{
    Node *temp = head;     // temp node
    Node *freeNode = NULL; // var to free deleted node
    int pos = 0;           // position of node in list
    int mid = 0;           // var for middle position of list
    int midRem = 0;        // var for remainder of pos % 2
    int i;                 // index for going through list
    int data1, data2;      // var to hold two mid vals for even-numbered list to compare

    if (head == NULL) // if empty list
    {
        printf("The list is empty.");
        return; // ends program early
    }

    while (temp) // counts number of nodes
    {
        temp = temp->next;
        pos++;
    }
    temp = head; // resets temp to head

    mid = pos / 2;    // gets middle number
    midRem = pos % 2; // determines of list is odd or even
    if (midRem == 1)  // in the case of an odd-numbered list
    {
        for (i = 0; i < mid - 1; i++)
        {
            temp = temp->next; // moves to middle node
        }
        freeNode = temp->next;           // assigns middle for deletion
        temp->next = temp->next->next;   // preserves links in list
        free(freeNode);                  // frees memory with node
        printf("Middle node deleted\n"); // to let the user know it worked
    }
    else // when list is even (has two "middle" nodes)
    {
        for (i = 1; i < mid; i++)
        {
            temp = temp->next; // moves to "left middle"
        }
        data1 = temp->data; // assigns "left middle" to data1
        temp = head;        // resets temp to head

        for (i = 1; i <= mid; i++)
        {
            temp = temp->next; // moves to "right middle"
        }
        data2 = temp->data; // assigns "right middle" to data2
        temp = head;        // resets temp to head

        if (data1 > data2) // "left middle" is greater
        {
            for (i = 1; i < mid - 1; i++) // goes to "left middle"
            {
                temp = temp->next;
            }
            freeNode = temp->next;           // assigns middle for deletion
            temp->next = temp->next->next;   // preserves links in list
            free(freeNode);                  // frees memory with node
            printf("Middle node deleted\n"); // to let the user know it worked
        }
        else // "right middle" is greater
        {
            for (i = 1; i < mid; i++) // goes to "right middle"
            {
                temp = temp->next;
            }
            freeNode = temp->next;           // assigns middle for deletion
            temp->next = temp->next->next;   // preserves links in list
            free(freeNode);                  // frees memory with node
            printf("Middle node deleted\n"); // to let the user know it worked
        }
    }
}