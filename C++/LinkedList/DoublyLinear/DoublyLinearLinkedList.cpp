/*
Program Name : Doubly Linear Linked List
Language     : C++
Description  : Implementation of Doubly Linear Linked List with basic operations
Author       : Tejas P Sutar

Operations:
1. InsertFirst
2. InsertLast
3. InsertAtPos
4. DeleteFirst
5. DeleteLast
6. DeleteAtPos
7. Display
8. Count
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:                // data hiding
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout<<"Object of DoublyLL gets created.\n";
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                newn->next = this->first;
                this->first->prev = newn;
                this->first = newn;
            }
            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                temp = this->first;
                
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;
            }
            this->iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;
                this->first = this->first->next;
                delete this->first->prev;
                this->first->prev = NULL;
            }
            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->next == NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            this->iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = this->first;
            cout<<"NULL <=> ";
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return this->iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            int iSize = 0;
            int iCnt = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;

            iSize = this->Count();
            if((pos < 1) || (pos > iSize+1))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iSize+1)
            {
                InsertLast(no);
            }
            else 
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                temp = this->first;
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next->prev = newn;

                temp->next = newn;
                newn->prev = temp;

                this->iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            int iSize = 0;
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            iSize = this->Count();
            if((pos < 1) || (pos > iSize))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iSize)
            {
                DeleteLast();
            }
            else 
            {
                temp = this->first;
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;
                temp->next = target->next;
                temp->next->prev = temp;
                delete target;

                this->iCount--;
            }
        }
};

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    obj.InsertAtPos(107, 4);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    obj.DeleteAtPos(2);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    return 0;
}
