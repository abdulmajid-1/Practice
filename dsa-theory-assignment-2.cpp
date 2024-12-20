#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class LinkedList
{
    Node *head;
    Node *tail;
    public:

    LinkedList()
    {
        head = tail = NULL;
    }
    void Insertatend(int d)
    {
        Node *n_node = new Node(d);
        if(head == NULL)
        {
           head = n_node;
           tail = n_node;
           n_node -> next = head;
        }
        else
        {
            Node *temp = head;
            while(temp -> next != head)
            {
                temp = temp -> next;
            }
            temp -> next = n_node;
            n_node -> next = head;
            tail = n_node;
        }
    }
    void treversal()
    {
        bool condition = true;
        Node *temp = head;
        if(head == NULL)
        {
            cout<<"Empty list!!!"<<endl;
        }
        else
        {
            cout<<"treversal : \n";
            while(condition == true)
            {
                cout<<temp->data<<"  ";
                temp = temp -> next;
                if(temp == head)
                {
                    condition = false;
                }
            }
            cout<<endl;
        }
    }
     void ReverseList()
    {

        bool condition = false;
        Node *next = NULL;
        Node *prev = tail;
        Node *current = head;
        Node *ogtail = tail;
        Node *oghead = head;
        if (head == NULL || head->next == head)
        {
            cout << "Cannot swap list !!!" << endl;
            return;
        }
        while(condition == false)
        {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
            if(next == oghead)
            {
                condition = true;
            }
            
          
        
        }
        tail = head;
        tail -> next = prev;
        head = prev;
    }
    void Display()
    {
        if (head == NULL) {
            cout << "Empty!!!" << endl;
            return;
        }

        Node *temp = head;
        while (true) 
        {
            cout << "Data: " << temp->data << endl;
            temp = temp->next;
            if (temp == head) 
            { 
                break;
            }
        }
        cout<<"head is : "<<head -> data <<" tail is : "<<tail -> next -> data<<endl;

}
void Insertsortedorder(int d)
{
    if(head == NULL)
    {
        cout<<"Empty "<<endl;
        return;
    }
    Node *n_node = new Node(d);
    Node *temp = head;
    Node *t_temp = tail;
    while(temp  -> next != head)
    {
       while(temp -> next != head)
       {
        if(temp -> next -> data < temp -> data)
        {
            t_temp -> next = temp -> next -> next;
            temp -> next -> next = temp;
            t_temp -> next = temp -> next;
        }
        t_temp = temp;
        temp = temp -> next;
       }
    }
}

};
int main()
{
    LinkedList l1;
    l1.Insertatend(1);
    l1.Insertatend(4);
    l1.Insertatend(3);
    l1.Insertsortedorder(2);
    l1.Display();
}