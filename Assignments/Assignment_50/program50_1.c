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

// Converts all negative elements in the linked list to positive
void MakeAbsolute(PNODE first)
{
    while (first != NULL)
    {
        if (first->data < 0)
        {
            first->data = -first->data;
        }
        first = first->next;
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

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, -10);
    InsertFirst(&head, 25);
    InsertFirst(&head, -30);
    InsertFirst(&head, 45);
    InsertFirst(&head, -50);
    InsertFirst(&head, 15);
    InsertFirst(&head, -20);


    printf("Linked list elements before MakeAbsolute:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    // Convert all negative elements to positive
    MakeAbsolute(head);
    printf("Linked list elements after MakeAbsolute:\n");
    Display(head);

    return 0;
}
