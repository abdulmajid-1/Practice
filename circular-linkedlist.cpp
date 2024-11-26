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
    void Insertatfront(int d)
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
            n_node -> next = head;
            head = n_node;
            tail -> next = head;
        }
    }

    void Insertatanywhere(int index,int d)
    {
        Node *n_node = new Node(d);
        if(head == NULL)
        {
            head = n_node;
            tail = n_node;
            n_node -> next = head;
            return;
        }
        if(head -> next == head)
        {
            head -> next = n_node;
            n_node -> next = head;
            tail = n_node;
        }
        else
        {
            Node *temp = head;
            int count = 1;
            while(temp ->next != head && count < index)
            {
                temp = temp -> next;
                count++;
            }
            if(temp -> next == head && count < index )
            {
                cout<<"Index out of bound !!!"<<endl;
                return;
            }
            if(temp -> next == head && count == index)
            {
                temp -> next = n_node;
                n_node -> next = head;
                tail = n_node;
                return;
            }
            n_node -> next = temp -> next;
            temp -> next = n_node;
        
        }
    }
    void deletefromlast()
    {
        if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    if (head->next == head) { 
        delete head;
        head = tail = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != tail) { 
        temp = temp->next;
    }

    delete tail; 
    tail = temp; 
    tail->next = head; 
       
    //   if (head == NULL) {
    //         cout << "Empty list" << endl;
    //         return;
    //     }
    
    //     if (head->next == head) {
    //         delete head;
    //         head = NULL;
    //         return;
    //     }
    
    //     Node *temp = head;
    //     while (temp->next->next != head) 
    //     {
    //         temp = temp->next;
    //     }
    //     delete temp -> next;
    //     temp -> next = head;
                 

    }
    void deletefromfront()
    {
         if(head == NULL)
        {
            cout<<"Empty list "<<endl;
            return;
        }
        if(head -> next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        head = head -> next;
        delete temp;
        tail -> next = head;
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
            while(temp -> next != head &&  count < (index - 1))
            {
                temp = temp -> next;
                count++;
            }
            if(temp -> next == head && count < index )
            {
                cout<<"Index out of bound !!!"<<endl;
                return;
            }
            if(temp -> next -> next == head && count == index)
            {
                delete temp -> next;
                temp -> next = head;
                return;
            }
            delete temp -> next;
            temp -> next = temp -> next -> next;
        }
    }
    void Display()
    {
        if (head == NULL) {
            cout << "Empty!!!" << endl;
            return;
        }

        Node *temp = head;
        while (true) {
            cout << "Data: " << temp->data << endl;
            temp = temp->next;
            if (temp == head) { // Stop when we've circled back to the head
                break;
            }
            cout<<"head is : "<<head -> data <<" tail is : "<<tail -> data<<endl;
        }
}
        // if(head == NULL)
        // {
        //     cout<<"Empty !!!"<<endl;
        //     return;
        // }
        // if(head -> next == head)
        // {
        //     cout<<"data is : "<<head -> data << endl;
        //     return;
        // }
        // Node *temp = head;
        // while(temp != head)
        // {
        //     cout<<"data is : " <<temp -> data;
        //     temp = temp -> next;
        // }
        // cout<<endl;
    //}

};
int main()
{
    // LinkedList l1;
    // l1.Insertatfront(2);
    // l1.Insertatend(4);
    // l1.Insertatfront(1);
    // l1.Insertatanywhere(2,3);
    // l1.Display();

    // cout <<endl;
    // l1.deletefromanywhere(3);
    // l1.Display();
    // cout<<endl;
    // l1.deletefromfront();
    // l1.Display();
    cout<<endl;
    // l1.deletefromlast();
    // l1.Display();
 

}