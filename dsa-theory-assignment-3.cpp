#include<iostream>
using namespace std;

class Node 
{
    public:
 //   int top;
    Node *next;
    char data;
    Node(char d)
    {
        data = d;
        next = NULL;
    }
};
class Stack
{
    public:
    Node *head;
    Stack()
    {
        head = NULL;
    }
    void Push(char d)
    {

        Node *n_node = new Node(d);
        if(head == NULL)
        {
            head = n_node;
            return;
        }
        n_node -> next = head;
        head = n_node;
    }

    char Pop()
    {
        if(head == NULL)
        {
            cout<<"empty !!! "<<endl;
        }
        else
        {
            Node *temp = head;
            head = head -> next;
            return temp -> data;
        }
        return 'h';
    }

    void Display()
    {
        if(head == NULL)
        {
            cout<<"Empty !!!"<<endl;
            return;
        }
        Node *temp = head;
        while(temp != NULL)
        {
            cout<< temp -> data << endl;
            temp = temp -> next;
        }
    }
  
};
int main()
{
    Stack s1;
    string ogst,newst;
    char arr[90];
    cout<<"Enter a string : "<<endl;
    cin>>ogst;
    for(int i = 0; ogst[i] != '\0';i++)
    {
        s1.Push(ogst[i]);
    }
    for(int i = 0; s1.head != NULL; i++)
    {
        arr[i] = s1.Pop();
    }
    newst = arr;
    cout<<"original string : "<<ogst<<endl;
    cout<<"Reversed string : "<<newst<<endl;

   // s1.Display();
    // s1.Push('h');
    // s1.Push('e');
    // s1.Push('l');
    // s1.Push('l');
    // s1.Push('o');
    // s2.Push(s1.Pop());
    // s2.Push(s1.Pop());
    // s2.Push(s1.Pop());
    // s2.Push(s1.Pop());
    // s2.Push(s1.Pop());


   // s1.Display();

    
}