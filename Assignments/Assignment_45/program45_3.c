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

// Find last occurrence of given number
int LastOccur(PNODE first, int no)
{
    int iPos = 0;
    int iCount = 1;

    while (first != NULL)
    {
        if (first->data == no)
        {
            iPos = iCount;
        }
        iCount++;
        first = first->next;
    }
    return iPos;
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
    int key = 11;

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

    iRet = LastOccur(head, key);

    if (iRet == 0)
    {
        printf("Number %d not found\n", key);
    }
    else
    {
        printf("Last occurrence of %d is at position : %d\n", key, iRet);
    }

    return 0;
}
