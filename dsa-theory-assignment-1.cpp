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
    public:
    Node *head;
    Node *tail;
   

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
        }
        else
        {
            Node *temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
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
        }
        else
        {
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
            return;
        }
        if(head -> next == NULL)
        {
            head -> next = n_node;
            n_node -> next = NULL;
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
            if(temp -> next == NULL && count < index )
            {
                cout<<"Index out of bound !!!"<<endl;
                return;
            }
            if(temp -> next == NULL && count == index)
            {
                temp -> next = n_node;
                n_node -> next = NULL;
                tail = n_node;
                return;
            }
            n_node -> next = temp -> next;
            temp -> next = n_node;
        
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
            head = head -> next;
            delete temp;
            return;
        }
        while(temp -> next -> next != NULL &&  temp -> next -> data != val)
        {
            temp = temp -> next;
        }
        if(val == temp -> next -> data && temp -> next == tail)
        {
            delete temp -> next;
            temp -> next = NULL;
            return;
        }
        if(temp -> next == NULL && temp -> data != val)
        {
            cout<<"Val not found!!!"<<endl;
            return;
        }
        Node *todel = temp -> next;
        temp -> next = temp -> next -> next;
        delete todel;
        todel = NULL; 

    }
        int searchbyvalue(int val)
    {
        if(head == NULL)
        {
            return -1;
        }
        Node *temp = head;
        int index = -1;
        while(temp -> next != NULL &&  temp -> data != val)
        {
            index++;
            temp = temp -> next;  
        }
        if(temp -> data == val)
        {
            return index + 1;
        }
        else
        {
            return -1;
        }
       
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
            if (temp == NULL) 
            { 
                break;
            }
        }

}
void findmiddlenode()
{
    if(head == NULL)
    {
        cout<<"Empty List !!!"<<endl;
        return;
    }
    Node *temp = head;
    Node *middlepointer = head;
    int counter = 0;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
        counter++;
        if(counter == 2)
        {
            middlepointer = middlepointer -> next;
            counter = 0;
        }
    }
    if(middlepointer == head)
    {
        cout<<"NO middle"<<endl;
        return;
    }
    cout<<"Middle node is : "<<middlepointer -> data<<endl;

}
void checkpalindrome()
{
    if(head == NULL)
    {
        cout<<"Empty !!!"<<endl;
        return;
    }
    Node *temp = head;
    Node *end = head;
    bool checker = false;
    while(end -> next != NULL)
    {
        end = end -> next;
    }
    while(end != temp)
    {
        if(end -> data == temp -> data)
        {
            temp = temp -> next;
            Node *t_end = temp;
            while(t_end -> next != end)
            {
                t_end = t_end -> next;
            }
            end = t_end;
            checker = true;
        }
        if(temp -> next == end)
        {
            cout<<"Palindrome "<<endl;
            return;
        }
        else
        {
            cout<<"Not a Palindrome !!!"<<endl;
            return;
        }
    }
    if(end == temp)
    {
        cout<<"Palindrome "<<endl;
    }
    if(checker == false)
    {
        cout<<"Not a Palindrome !!!"<<endl;
        return;
    }
}
void ReverseList()
{
    Node *prev = NULL;      
    Node *current = head;   
    Node *next = NULL;       
    Node *oghead = head;
    Node *ogtail = tail;

    if (head == NULL || head->next == NULL)
    {
        cout << "List is already reversed or empty!" << endl;
        return;
    }
    
    else
    {

    

        while (current != NULL)
        {
            next = current->next;   // Store the next node
            current->next = prev;   // Reverse the current node's pointer
            prev = current;         // Move 'prev' to the current node
            current = next;         // Move to the next node
        }
    }
    tail = oghead;
    head = ogtail;

  
}
void priroty(int m, int n)
{
    if(head == NULL)
    {
        cout<<"Empty !!!"<<endl;
        return;
    }
    Node *temp = head;
    Node *t_head = head;
    Node *newhead = NULL;
    Node *newtail = NULL;
    Node *lasttail = NULL;
    // just to store the original m and n
    int temp_m = m; 
    int temp_n = n;
    bool checker = true;
    while(temp != NULL)
    {
        m = temp_m;
        n = temp_n;
        while(m > 1 && temp -> next != NULL)
        {
            temp = temp -> next;
            m--;
        }
        if(temp -> next == NULL)
            return;
        newtail = temp;
        newhead = temp -> next;
        while(n > 0 && temp -> next != NULL)
        {
            temp = temp -> next;
            n--;
        }
        if(checker == true)
        {
            lasttail = newtail;
        }
        newtail -> next = temp ->next;
        temp -> next = t_head;
        if(checker == true)
        {
            head = newhead;
        }
        temp = newtail -> next;
        t_head = temp;
        if(checker == false)
        {
            lasttail -> next = newhead;
        }
        checker = false;


    }
}
void removal(int i , int j)
{
    if(head == NULL)
    {
        return;        
    }
    Node *temp = head;
    Node *prev = NULL;
    Node *todel = NULL;
    int t_i = i;
    int t_j = j;
    while(temp != NULL)
    {
        i = t_i;
        j = t_j;
    while (i > 0 && temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
        i--;
    }    
    while(j > 0 && temp != NULL)
    {
        todel = temp;
        temp = temp -> next;
        delete todel;
        j--;
    }
        prev -> next = temp;
        
    }

}


};
void Merge(LinkedList l1, LinkedList l2)
{   
    if(l1.head == NULL || l2.head == NULL)
    {
        cout<<"Cannot Merge !!!"<<endl;
        return;
    }
    l1.tail->next = l2.head;
    l1.tail = NULL;
    l2.head = NULL;
    Node *temp = l1.head;
    while (temp != NULL)
    {
        cout << "data is : " << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    LinkedList l1;
    LinkedList l2;
    l1.Insertatanywhere(0,1);
    l1.Insertatend(2);
    l1.Insertatend(3);
    l1.Insertatend(4);
    // l1.Insertatend(5);
    // l1.Insertatend(6);
    //l1.findmiddlenode();
    // l1.checkpalindrome();
    // l2.Insertatend(5);
    // l2.Insertatend(6);
    // l1.Insertatend(5);
    // l1.Insertatend(6);
    // l1.Insertatend(7);
    // l1.Insertatend(8);
    // l1.Insertatend(9);
    // l1.Insertatend(10);
    //Merge(l1,l2);
    // cout<<"Before reverse : "<<endl;
    // l1.Display();
    // cout<<"After reverse : "<<endl;
    // l1.ReverseList();
    // cout<<"Before removing : "<<endl;    
    l1.priroty(2,2);
    l1.Display();
    // l1.removal(2,2);

   //s cout<<"Index : "<<l1.searchbyvalue(22)<<endl;
//    cout<<"l1 data : "<<endl;
    // cout<<"After removal  : "<<endl;
    // l1.Display();
//   cout<<"l2 data : "<<endl;
//   l2.Display();
//   cout<<"After merge : "<<endl;
//   Merge(l1,l2);
    return 0;
}