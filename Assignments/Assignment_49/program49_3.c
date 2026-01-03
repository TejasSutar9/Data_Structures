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

// Displays elements from the linked list which are divisible by 3
void DisplayDivByThree(PNODE first)
{
    while (first != NULL)
    {
        if (first->data % 3 == 0)
        {
            printf("%d  ", first->data);
        }
        first = first->next;
    }
    printf("\n");
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

    printf("Elements divisible by 3 are : ");
    DisplayDivByThree(head);

    return 0;
}
