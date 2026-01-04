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
        *first = newn;
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

// Calculate and display sum of digits for each node
void SumDigits(PNODE first)
{
    printf("Sum of digits of each node:\n");
    printf("--------------------------------\n");

    while (first != NULL)
    {
        int iNum = first->data;
        int temp = iNum;
        int iSum = 0;

        if (temp == 0)
            iSum = 0;
        else
        {
            while (temp != 0)
            {
                iSum += temp % 10;
                temp = temp / 10;
            }
        }

        printf("| %-6d | -> %d\n", iNum, iSum);
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
    InsertFirst(&head, 82);
    InsertFirst(&head, 7);
    InsertFirst(&head, 405);
    InsertFirst(&head, 56);
    InsertFirst(&head, 9999);
    InsertFirst(&head, 1);
    InsertFirst(&head, 123);

    printf("Linked list elements:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes after InsertFirst are : %d\n", iRet);
    printf("-------------------------------------------------------------\n");

    // Sum of digits for each node
    SumDigits(head);

    return 0;
}

