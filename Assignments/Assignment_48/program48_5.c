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

// Display elements at odd positions
void DisplayOddPosition(PNODE first)
{
    int iPos = 1;
    printf("Elements at odd positions:\n");
    while (first != NULL)
    {
        if (iPos % 2 != 0)
        {
            printf("%d\t", first->data);
        }
        first = first->next;
        iPos++;
    }
    printf("\n");
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

    // Insert 
    InsertFirst(&head, 5);
    InsertFirst(&head, 10);
    InsertFirst(&head, 15);
    InsertFirst(&head, 20);
    InsertFirst(&head, 25);
    InsertFirst(&head, 30);
    InsertFirst(&head, 35);

    printf("Linked list elements:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    // Display elements at odd positions
    DisplayOddPosition(head);

    return 0;
}

