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

// Count elements less than given number
int CountLess(PNODE first, int X)
{
    int iCount = 0;

    while (first != NULL)
    {
        if (first->data < X)
        {
            iCount++;
        }
        first = first->next;
    }
    return iCount;
}

// Display linked list
void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

// Count total nodes
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
    int X = 25;

    InsertFirst(&head, 51);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);
    InsertFirst(&head, 50);
    InsertFirst(&head, 22);
    InsertFirst(&head, 11);
    InsertFirst(&head, 24);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("-------------------------------------\n");

    iRet = CountLess(head, X);

    if (iRet == 0)
    {
        printf("No elements less than %d\n", X);
    }
    else
    {
        printf("Count of elements less than %d is : %d\n", X, iRet);
    }

    return 0;
}
