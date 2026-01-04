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

// Count digits of each node's data
void CountDigits(PNODE first)
{
    printf("Number of digits in each node:\n");
    printf("---------------------------------\n");

    while (first != NULL)
    {
        int iNum = first->data;
        int temp = iNum;
        int iCount = 0;

        if (temp == 0)
            iCount = 1;
        else
        {
            while (temp != 0)
            {
                temp = temp / 10;
                iCount++;
            }
        }

        printf("| %-5d | -> %d digits\n", iNum, iCount);

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

    // Insert new/different elements
    InsertFirst(&head, 123);
    InsertFirst(&head, 7);
    InsertFirst(&head, 405);
    InsertFirst(&head, 56);
    InsertFirst(&head, 9999);
    InsertFirst(&head, 1);
    InsertFirst(&head, 82);

    printf("Linked list elements:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    CountDigits(head);

    return 0;
}

