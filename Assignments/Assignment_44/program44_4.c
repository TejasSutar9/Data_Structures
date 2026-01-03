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

// Count frequency of given number
int Frequency(PNODE first, int no)
{
    int iFrequency = 0;

    while (first != NULL)
    {
        if (first->data == no)
        {
            iFrequency++;
        }
        first = first->next;
    }
    return iFrequency;
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
    int key = 11;

    InsertFirst(&head, 101);
    InsertFirst(&head, 78);
    InsertFirst(&head, 11);
    InsertFirst(&head, 44);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    InsertFirst(&head, 12);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("---------------------------------------------------------------\n");

    iRet = Frequency(head, key);
    printf("Frequency of %d is : %d\n", key, iRet);

    return 0;
}
