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

// Calculates the difference between maximum and minimum element in the linked list
int Difference(PNODE first)
{
    int iMax = first->data;
    int iMin = first->data;

    while (first != NULL)
    {
        if (first->data > iMax)
        {
            iMax = first->data;
        }

        if (first->data < iMin)
        {
            iMin = first->data;
        }

        first = first->next;
    }

    return (iMax - iMin);
}

// Displays all elements of the linked list
void Display(PNODE first)
{
    while (first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

// Counts total number of nodes in the linked list
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

    InsertFirst(&head, 30);
    InsertFirst(&head, 15);
    InsertFirst(&head, 40);
    InsertFirst(&head, 10);
    InsertFirst(&head, 25);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("-----------------------------------------\n");

    iRet = Difference(head);
    printf("Difference between maximum and minimum is : %d\n", iRet);

    return 0;
}
