#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Checks whether all elements in the linked list are positive
bool CheckAllPositive(PNODE first)
{
    bool isPositive = true;

    while (first != NULL)
    {
        if (first->data < 0)
        {
            isPositive = false;
            break;
        }
        first = first->next;
    }
    return isPositive;
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
    bool bRet = false;

    InsertFirst(&head, 30);
    InsertFirst(&head, 15);
    InsertFirst(&head, 40);
    InsertFirst(&head, 10);
    InsertFirst(&head, 25);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("-----------------------------------------\n");

    bRet = CheckAllPositive(head);

    if (bRet == true)
    {
        printf("All elements in the linked list are POSITIVE\n");
    }
    else
    {
        printf("Linked list contains NEGATIVE elements\n");
    }

    return 0;
}

