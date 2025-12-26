// Language : C++
// Singly Linear

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLL
{
    private:                // data hiding
        PNODE first;
        int iCount;

    public:
        SinglyLL()
        {
            cout<<"Object of SinglyLL gets created\n";
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }

            else
            {
                newn->next = first;
                first = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }

            else
            {
                temp = first;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
            }
            iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }

            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }

            else 
            {
                temp = first;

                first = first->next;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }

            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }

            else 
            {
                temp = first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = first;
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            int iSize = 0;
            int iCnt = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;

            iSize = Count();
            if((pos < 1) || (pos > iSize+1))
            {
                cout<<"Invalid Position\n";
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

                temp = first;
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            int iSize = 0;
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            iSize = Count();
            if((pos < 1) || (pos > iSize))
            {
                cout<<"Invalid Position\n";
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
                temp = first;
                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }
                target = temp->next;
                temp->next = target->next;
                delete target;

                iCount--;
            }
        }

        
};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(151);

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

    obj.InsertAtPos(105, 2);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    obj.DeleteAtPos(2);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are : "<<iRet<<"\n\n";

    return 0;
}