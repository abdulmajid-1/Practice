#include<iostream>
using namespace std;

class Node 
{
    public:
    Node *next;
    int data;
    Node(char d)
    {
        data = d;
        next = NULL;
    }
};
class Stack
{
    public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void Push(int d)
    {

        Node *n_node = new Node(d);
        if(top == NULL)
        {
            top = n_node;
            return;
        }
        n_node -> next = top;
        top = n_node;
    }

    int Pop()
    {
        if(top == NULL)
        {
            cout<<"empty !!! "<<endl;
        }
        else
        {
            Node *temp = top;
            top = top -> next;
            return temp -> data;
        }
        return -1;
    }

    void Display()
    {
        if(top == NULL)
        {
            cout<<"Empty !!!"<<endl;
            return;
        }
        Node *temp = top;
        while(temp != NULL)
        {
            cout<< temp -> data << endl;
            temp = temp -> next;
        }
    }
    void Deletemiddle()
    {
        if(top == NULL || top -> next == NULL || top -> next -> next == NULL)
        {
            cout<<"Not possible !!!"<<endl;
            return;
        }
        Node *temp = top;
        Node *middle = top;
        Node *beforemiddle = NULL;
        int i = 0;
        while(temp  != NULL)
        {
            if(i == 2)
            {
                beforemiddle = middle;
                middle = middle -> next;
                i = 0;
            }
            temp = temp -> next;
            i++;

        }
        beforemiddle -> next = middle -> next;
        delete middle;
        
    }
   
  
};
void Reversearray(int arr[],int size)
{
    Stack s1;
    cout<<"Original array is : \n";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    for(int i = 0; i < size ; i++)
    {
        s1.Push(arr[i]);   
    }
    for(int i = 0; i < size ; i++)
    {
        arr[i] = s1.Pop();
    }
    cout<<"Reversed array is : \n";

    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    Stack s1;
    int arr[] = {20,30,40,50};
    int size = sizeof(arr)/sizeof(int);
   // Reversearray(arr,size);
    s1.Push(7);
    s1.Push(6);
    s1.Push(5);
    s1.Push(4);
    s1.Push(3);
    s1.Push(2);
    s1.Push(1);
    s1.Deletemiddle();
    s1.Display();


    
   

   
   


}
