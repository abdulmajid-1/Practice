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
        cout<<"head is : "<<head -> data <<" tail is : "<<tail -> data<<endl;

}

// void Removeduplicates()

// {
//     if(head == NULL || head -> next == NULL)
//     {
//         cout<<"not possible "<<endl;
//         return;
//     }

//     Node *outertemp = head;
//     // while(prev -> next != head)
//     // {
//     //     prev = prev -> next;
//     // }
//     while(tail -> next != head)
//     {
//         tail = tail -> next;
//     }
//     while(outertemp  -> next != head)
//     {
        
//         Node *temp = head;
//         Node *Next = temp -> next;
//         Node *prev = tail;

//        while(temp -> next != head && Next != head)
//        {
//         if(temp -> data > temp -> next -> data)
//         {
//             if(temp == head)
//             {
//                 head = temp -> next;
//             }
//             if(Next -> next == head)
//             {
//                 tail = temp;
//             }
//             prev -> next = Next;
//             temp -> next = Next -> next;
//             Next -> next = temp;
         
//         }
//         temp = temp -> next;
//         Next = temp -> next;
//         prev = prev -> next;
//        }
//        outertemp = outertemp->next;
 
//    }
// }
void Removeduplicate()
{
    if(head == NULL || head ->next == head)
    {
        cout<<"Not possible !!!"<<endl;
        return;
    }
    Node *prev = tail;
    Node *temp = head;
    while(temp -> next  != head)
    {
        while(temp -> data == temp -> next -> data)
        {
            Node *NEXT = temp -> next;
            if(NEXT == tail)
            {
                tail = temp;
            }
            temp -> next = NEXT -> next;
            delete NEXT;
            temp = temp -> next;
            prev = prev -> next;

        }
        temp = temp -> next;
        prev = prev -> next;
    }
}
void Insertsortedorder(int d)
{
    Node *n_node = new Node(d);
    Node *temp = head;
    if(head == NULL)
    {
        n_node ->next = n_node;
        head = tail = n_node;
        return;
    }
    if(head -> next == head)
    {
        if(head -> data <= n_node -> data)
        {
            head -> next = n_node;
            n_node -> next = head;
        }
        else
        {
            head -> next = n_node;
            n_node -> next = head;
            head = n_node;
        }
    }
    if (d <= head->data)
    {
        tail -> next = n_node;
        n_node -> next = head;
        head = n_node;
        return;
    }
    while (temp->next != head && temp->next->data < d)
    {
        temp = temp->next;
    }

    n_node->next = temp->next;
    temp->next = n_node;

    if (temp == tail)
    {
        tail = n_node;
    }
    
}

};
int main()
{
    LinkedList l1;
    l1.Insertatend(1);
    l1.Insertatend(1);
    l1.Insertatend(1);
    l1.Insertatend(3);
    l1.Insertatend(3);
    l1.Insertatend(3);
    l1.Insertatend(4);
    l1.Insertatend(4);
    l1.Insertatend(4);
   // l1.Insertatend(-1);
    //l1.Removeduplicate();
    l1.Insertsortedorder(2);

    l1.Display();
}