#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        prev = NULL;
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
           n_node -> next = NULL;
        }
        else
        {
            Node *temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            n_node -> prev = temp;
            temp -> next = n_node;
            n_node -> next = NULL;
            tail = n_node;
        }
    }
    void Insertatfront(int d)
    {
        Node *n_node = new Node(d);
        if(head == NULL)
        {
            head = n_node;
            tail = n_node;
            n_node -> next = NULL;
        }
        else
        {
            head -> prev = n_node;
            n_node -> next = head;
            head = n_node;
        }
    }

    void Insertatanywhere(int index,int d)
    {
        Node *n_node = new Node(d);
        if(head == NULL)
        {
            head = n_node;
            tail = n_node;
            n_node -> next = NULL;
        }
        else
        {
            Node *temp = head;
            int count = 1;
            while(temp!= NULL && count < index)
            {
                temp = temp -> next;
                count++;
            }
            if(temp == NULL)
            {
                cout<<"Index out of bound !!!"<<endl;
                return;
            }
            if(temp == head)
            {
                Insertatend(d);
                return;
            }
            if(temp -> next == NULL)
            {
                n_node -> prev = temp;
                temp -> next = n_node;
                n_node -> next = NULL;
                tail = n_node;
                return;
            }
            n_node -> prev = temp -> prev;
            n_node -> next = temp;
            temp -> prev -> next = n_node;
            temp -> prev = n_node;
        
        }
    }
    void deletefromlast()
    {
       
      if (head == NULL) {
            cout << "Empty list" << endl;
            return;
        }
    
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
    
        Node *temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
    
        temp->prev->next = NULL;  
        delete temp;              

    }
    void deletefromfront()
    {
         if(head == NULL)
        {
            cout<<"Empty list "<<endl;
            return;
        }
        Node *temp = head;
        head = head -> next;
        delete temp;
        temp = NULL;
    }
    void deletefromanywhere(int index)
    {
        if(head == NULL)
        {
            cout<<"Empty list "<<endl;
            return;

        }
        else
        {
            Node *temp = head;
            int count = 1;
            while(temp != NULL && index > count)
            {
                temp = temp -> next;
                count++;
            }
            if(temp == NULL)
            {
                cout<<"Index out of bound !!!"<<endl;
                return;
            }
            if(temp == head )
            {
                deletefromfront();
                return;
            }
            if(temp -> next == NULL)
            {
                deletefromlast();
                return;
            }
            temp -> next -> prev = temp -> prev;
            temp -> prev -> next = temp -> next;
            delete temp;
        }
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
            cout<<temp -> data <<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

};
int main()
{
    LinkedList l1;
    l1.Insertatfront(3);
    l1.Insertatend(4);
    l1.Insertatfront(1);
    l1.Insertatanywhere(2,2);
    l1.Display();
    l1.deletefromanywhere(3);
    l1.Display();

    l1.deletefromfront();
    l1.Display();

    l1.deletefromlast();
    l1.Display();


}