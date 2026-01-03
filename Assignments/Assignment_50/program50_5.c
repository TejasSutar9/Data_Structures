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
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*first == NULL)
        *first = newn;
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

// Count nodes present at every Nth position
int DisplayNthPos(PNODE first, int n)
{
    int iPos = 1;
    int iCount = 0;

    if (n <= 0)
        return 0;

    while (first != NULL)
    {
        if (iPos % n == 0)
        {
            iCount++;
        }
        iPos++;
        first = first->next;
    }
    return iCount;
}

// Display all elements of the linked list
void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

// Count total nodes in the linked list
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

    // Count nodes at 2nd position
    iRet = DisplayNthPos(head, 2);
    printf("Count of nodes at 2nd position : %d\n", iRet);

    return 0;
}
