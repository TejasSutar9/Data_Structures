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

// Search number in linked list
bool Search(PNODE first, int no)
{
    while (first != NULL)
    {
        if (first->data == no)
        {
            return true;
        }
        first = first->next;
    }
    return false;
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

// Count nodes
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
    int key = 21;   // number to search

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("-------------------------------------\n");

    bRet = Search(head, key);
    if (bRet == true)
    {
        printf("Number %d is present in linked list\n", key);
    }
    else
    {
        printf("Number %d is not present in linked list\n", key);
    }

    return 0;
}
