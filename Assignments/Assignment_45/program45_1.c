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

// Display odd elements
void DisplayOdd(PNODE first)
{
    printf("Odd elements are : ");
    while (first != NULL)
    {
        if ((first->data % 2) != 0)
        {
            printf("%d ", first->data);
        }
        first = first->next;
    }
    printf("\n");
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

    InsertFirst(&head, 35);
    InsertFirst(&head, 42);
    InsertFirst(&head, 17);
    InsertFirst(&head, 60);
    InsertFirst(&head, 29);
    InsertFirst(&head, 18);
    InsertFirst(&head, 41);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("-------------------------------------\n");

    DisplayOdd(head);

    return 0;
}
