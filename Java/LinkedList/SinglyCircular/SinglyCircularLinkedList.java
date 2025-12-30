/*
Program Name : Singly Circular Linked List
Language     : Java
Description  : Implementation of Singly Circular Linked List with basic operations
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

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created.");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first = newn;
        }
        this.last.next = this.first;
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
        }
        this.last.next = this.first;
        this.iCount++;
    }

    public void DeleteFirst()
    {
        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.first = this.first.next;
            this.last.next = this.first;
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.first;

            while(temp.next != this.last)
            {
                temp = temp.next;
            }

            this.last = temp;
            this.last.next = this.first;
        }

        System.gc();
        this.iCount--;
    }

    public void Display()
    {
        node temp = null;

        if(this.first == null && this.last == null)
        {
            return;
        }

        temp = this.first;
        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }
        while(temp != this.last.next);

        System.out.println();
    }

    public int Count()
    {
        return this.iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;

        int iCnt = 0;

        if(pos < 1 || pos > this.iCount+1)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(pos == this.iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new node(no);

            temp = this.first;
            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            this.iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            this.DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            System.gc();
            this.iCount--;
        }
    }
}

class SinglyCircularLinkedList
{
    public static void main(String A[])
    {
        SinglyCL obj = null;
        int iRet = 0;

        obj = new SinglyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.DeleteAtPos(4);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}