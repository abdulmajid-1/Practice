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
            if(head -> next == head)
            {
                delete head ;
                head = tail = NULL;
                return;
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
                tail = temp;
                return;
            }
            Node *todel = temp -> next;
            temp -> next = temp -> next -> next;
            delete todel;
            todel = NULL;
            
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
    void deletebyvalue(int val)
    {
        if(head == NULL)
        {
            cout<<"Empty!!!"<<endl;
            return;
        }
        Node *temp = head;
        if(temp -> data == val)
        {
            deletefromfront();
            return;
        }
        while(temp -> next -> next != head &&  temp -> next -> data != val)
        {
            temp = temp -> next;
        }
        if(val == temp -> next -> data && temp -> next == tail)
        {
            deletefromlast();
            return;
        }
        if(temp -> next == head && temp -> data != val)
        {
            cout<<"Val not found!!!"<<endl;
            return;
        }
        Node *todel = temp -> next;
        temp -> next = temp -> next -> next;
        delete todel;
        todel = NULL;
        

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

};
int main()
{
    LinkedList l1;
    l1.Insertatfront(2);
    l1.Insertatend(4);
    l1.Insertatfront(1);
    l1.Insertatanywhere(2,3);
    l1.Display();
    cout <<endl;
    l1.deletefromanywhere(3);
    l1.Display();
    cout<<endl;
    l1.deletefromfront();
    l1.Display();
    cout<<endl;
    l1.deletefromlast();
    l1.Display();
    l1.deletefromanywhere(1);
    l1.deletefromfront();
    l1.deletefromlast();
    l1.Display();
    l1.treversal();
    l1.deletebyvalue(4);
    l1.ReverseList();
    l1.Display();
 

}