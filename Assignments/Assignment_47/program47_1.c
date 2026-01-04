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

// Display linked list in reverse using array
void DisplayReverse(PNODE first)
{
    int Arr[100];  // temporary array
    int i = 0;
    int iCnt = 0;

    while (first != NULL)
    {
        Arr[i] = first->data;
        i++;
        first = first->next;
    }

    printf("Linked list in reverse order:\n");
    for (iCnt = i - 1; iCnt >= 0; iCnt--)
    {
        printf("| %d | -> ", Arr[iCnt]);
    }
    printf("NULL\n");
}

// Display linked list normally
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

    // Insert elements into linked list
    InsertFirst(&head, 51);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);
    InsertFirst(&head, 50);
    InsertFirst(&head, 22);
    InsertFirst(&head, 11);
    InsertFirst(&head, 24);

    printf("Linked list elements:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("-------------------------------------\n");

    // Display in reverse
    DisplayReverse(head);

    return 0;
}

