#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

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

// Count odd elements
int CountOdd(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        if ((first->data % 2) != 0)
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

    InsertFirst(&head, 101);
    InsertFirst(&head, 87);
    InsertFirst(&head, 51);
    InsertFirst(&head, 44);
    InsertFirst(&head, 21);
    InsertFirst(&head, 16);
    InsertFirst(&head, 12);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("---------------------------------------------------------------\n");

    iRet = CountOdd(head);
    printf("Count of odd numbers is : %d\n", iRet);

    return 0;
}
