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

// Insert node at beginning 
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

// Count how many elements are two-digit numbers
int CountTwoDigit(PNODE first)
{
    int iTwoDigit = 0;
    
    while (first != NULL)
    {
        int iCount = 0;
        int iNum = first->data;

        while (iNum != 0)
        {
            iNum = iNum / 10;
            iCount++;
        }

        if (iCount == 2)
        {
            iTwoDigit++;
        }
        
        first = first->next;
    }

    return iTwoDigit;
}

// Display all elements of linked list
void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | ->", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

// Count total number of nodes in linked list
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

    // Insert elements into linked list
    InsertFirst(&head, 51);
    InsertFirst(&head, 120);
    InsertFirst(&head, 30);
    InsertFirst(&head, 520);
    InsertFirst(&head, 22);
    InsertFirst(&head, 111);
    InsertFirst(&head, 24);

    // Display linked list
    Display(head);

    // Count total nodes
    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    // Count two-digit elements
    iRet = CountTwoDigit(head);
    printf("Count of two digit elements is : %d\n", iRet);

    return 0;
}
