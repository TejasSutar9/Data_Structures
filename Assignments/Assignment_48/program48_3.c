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

// Multiply each node by 2
void MultiplyByTwo(PNODE first)
{
    while (first != NULL)
    {
        first->data = first->data * 2;
        first = first->next;
    }
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

    // Insert 
    InsertFirst(&head, 7);
    InsertFirst(&head, 14);
    InsertFirst(&head, 9);
    InsertFirst(&head, 20);
    InsertFirst(&head, 5);
    InsertFirst(&head, 12);
    InsertFirst(&head, 8);

    printf("Linked list before multiplying by 2:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    // Multiply each node by 2
    MultiplyByTwo(head);
    printf("Linked list after multiplying each element by 2:\n");
    Display(head);

    return 0;
}

