#include<iostream>
using namespace std;

class Node 
{
    public:
        Node *next;
        int data;
        Node(int d)
        {
            next = NULL;
            data = d;
        }
};
class Queue
{
    Node *top;
    Node *End;
    public:
    Queue()
    {
        top = End = NULL;
    }
    void Enqueue(int d)
    {
        Node *n_node = new Node(d);
        if(top == NULL)
        {
            top = End = n_node;
            return;
        }
        n_node -> next = top;
        top = n_node;

    }
    int Dequeue()
    {
        if(top == NULL)
        {
            cout<<"Empty !!!"<<endl;
            return -1;
        }
        else
        {
            Node *temp = top;
            int d;
            if(temp -> next == NULL)
            {
                d = temp -> data;
                delete temp;
                top = NULL;
                return d;
            }
            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }
            End = temp;
            d = temp -> next -> data;
            delete temp -> next;
            temp -> next = NULL;

            return d;

        }
    }
    void Print()
    {
        if(top == NULL)
        {
            cout<<"Empty !!!"<<endl;
            return;
        }
        Node *temp = top;
        while(temp != NULL)
        {
            cout<<temp -> data<<endl;
            temp = temp -> next;
        }
    }

};
int main()
{
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
   // q1.Dequeue();
    cout<<q1.Dequeue()<<endl;
    q1.Print();
    cout<<q1.Dequeue()<<endl;
    q1.Print();

}