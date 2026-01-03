#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

// Insert a new node at the beginning
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

// Displays all elements of the linked list
void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | ->", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

// Counts the total number of nodes in the linked list
int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

// Displays all elements greater than the average of the list
void DisplayGreaterThanAverage(PNODE first)
{
    PNODE temp = NULL;

    int iSize = Count(first);
    int iSum = 0;
    int iAverage = 0;

    temp = first;

    while (temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }

    iAverage = (iSum / iSize);

    printf("Elements greater than average:\n");
    temp = first;

    while (temp != NULL)
    {
        if (temp->data > iAverage)
        {
            printf("%d\t", temp->data);
        }

        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 10);
    InsertFirst(&head, 25);
    InsertFirst(&head, 30);
    InsertFirst(&head, 45);
    InsertFirst(&head, 50);
    InsertFirst(&head, 15);
    InsertFirst(&head, 20);

    printf("Linked list elements:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    // Display elements greater than average
    DisplayGreaterThanAverage(head);

    return 0;
}
