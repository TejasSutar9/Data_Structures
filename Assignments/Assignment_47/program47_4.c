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

// Display all prime numbers in linked list
void DisplayPrime(PNODE first)
{
    printf("Prime numbers in the linked list:\n");
    printf("---------------------------------\n");

    while (first != NULL)
    {
        int iNum = first->data;
        int isPrime = 1;

        if (iNum <= 1)
        {
            isPrime = 0;
        }
        else
        {
            for (int i = 2; i * i <= iNum; i++)
            {
                if (iNum % i == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime)
        {
            printf("%d\t", iNum);
        }

        first = first->next;
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

    // Insert different elements into linked list
    InsertFirst(&head, 17);
    InsertFirst(&head, 33);
    InsertFirst(&head, 29);
    InsertFirst(&head, 44);
    InsertFirst(&head, 5);
    InsertFirst(&head, 18);
    InsertFirst(&head, 7);

    printf("Linked list elements:\n");
    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n", iRet);
    printf("-------------------------------------\n");

    // Display prime numbers
    DisplayPrime(head);

    return 0;
}
