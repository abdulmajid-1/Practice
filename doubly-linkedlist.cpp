// Doubly Linked List (DLL) 
// ⦁	Implement a simple doubly linked list where you can perform basic operations like insert at the beginning, insert at the end, delete from the beginning, and delete from the end.
// ⦁	Implement insert and delete operations at a specific position in the doubly linked list, where the user can specify the index.
// ⦁	Implement a function to reverse the entire doubly linked list without using extra space.
// ⦁	Search for a node with a given value and delete it from the doubly linked list.
// ⦁	Implement a function to display the list from the head to the tail and from the tail to the head.
// ⦁	Write a program to merge two doubly linked lists into a single sorted doubly linked list.
// ⦁	Implement a function to count the number of nodes in a doubly linked list.
// ⦁	Write a function to delete all occurrences of a specific value in the doubly linked list.

#include <iostream>
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
        next = NULL;
        prev = NULL;
    }
};
class Linklist
{
public:
    Node *head = NULL;
    Node *tail = NULL;

public:
    void insertatlast(int d)
    {

        Node *n_node = new Node(d);

        if (head == NULL)
        {
            head = n_node;
            tail = n_node;
        }
        else
        {
            tail->next = n_node;
            n_node->prev = tail;
            tail = n_node;
            tail->next = NULL;
        }
    }
    void InsertatFront(int d)
    {
        Node *n_node = new Node(d);
        if (head == NULL)
        {
            head = n_node;
            tail = n_node;
        }

        else
        {
            n_node->next = head;
            head->prev = n_node;
            head = n_node;
        }
    }
    void Insetatanywhere(int index, int d)
    {

        if (index < 0)
        {
            cout << "Invalid index!" << endl;
            return;
        }
        if (index == 0)
        {
            InsertatFront(d);
            return;
        }
        Node *temp = head;
        int count = 0;
        while ((count < index - 1) && (temp != NULL))
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            cout << "index out of bounds!" << endl;
            return;
        }
        if (temp->next == NULL)
        {
            insertatlast(d);
            return;
        }
        // installing in between

        Node *n_node = new Node(d);
        n_node->next = temp->next;
        n_node->prev = temp;
        n_node->next->prev = n_node;
        temp->next = n_node;
    }
    void Deletefromlast()
    {
        if (head == NULL)
        {
            cout << "Empty Linked list !!!" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    void Deletefromfront()
    {
        if (head == NULL)
        {
            cout << "Empty Linked list !!!" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    void deletefromanywhere(int index)
    {

        if (head == NULL)
        {
            cout << "Empty Linked list!!!" << endl;
            return;
        }
        if (index == 0)
        {
            Deletefromfront();
            return;
        }
        Node *temp = head;
        int count = 0;
        while (count < index - 1 && temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Deletion request is out of bound !!!!" << endl;
            return;
        }

        Node *n_node = temp->next;
        temp->next = n_node->next;
        if (n_node->next != NULL)
        {
            n_node->next->prev = temp;
        }
        else
        {
            tail = temp;
        }
        delete n_node;
    }
    void Deletewithvalue(int val)
    {
        if (head == NULL)
        {
            cout << "Empty list!!!" << endl;
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == val && temp == head)
            {
                Deletefromfront();
                return;
            }
            if (temp->data == val && temp == tail)
            {
                Deletefromlast();
                return;
            }
            if (temp->data == val)
            {

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Value is not in the list!!!" << endl;
            return;
        }
    }

    void ReverseList()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Cannot swap list !!!" << endl;
            return;
        }
        Node *temp = head;
        Node *current = head;

        while (temp != NULL)
        {
            temp->prev = temp->next;
            if (head == temp)
            {
                temp->next = NULL;
                temp = temp->prev;
                continue;
            }
            temp->next = current;
            temp = temp->prev;
            current = current->prev;
        }
        tail = head;
        head = current;
    }
    void Displayheadtotail()
    {
        if (head == NULL)
        {
            cout << "Empty List!!!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "Data is : " << temp->data << endl;

            temp = temp->next;
        }
        cout << "Head is " << head->data << " tail is " << tail->data << endl;
    }
    void Displaytailtohead()
    {
        if (head == NULL)
        {
            cout << "List is Empty!!!" << endl;
            return;
        }
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << "Data is : " << temp->data << endl;
            temp = temp->prev;
        }
    }
    void Counter()
    {
        if (head == NULL)
        {
            cout << "Empty list !!!" << endl;
            return;
        }
        int count = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        cout << "Total nodes are : " << count << endl;
    }
    void deleteallval(int val)
    {
        if (head == NULL)
        {
            cout << "Empty list!!!!" << endl;
            return;
        }

        Node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                found = true;
                Node *toDelete = temp;

                if (temp == head)
                    head = head->next;
                if (temp == tail)
                    tail = tail->prev;

                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;

                temp = temp->next;
                delete toDelete;
            }
            else
            {
                temp = temp->next;
            }
        }

        if (!found)
        {
            cout << "Value is not in the list!!!" << endl;
        }

        if (head == NULL)
            tail = NULL;
    }

    // void deleteallval(int val)
    // {
    //     bool found = 0;

    //     if (head == NULL)
    //     {
    //         cout << "Empty list!!!!" << endl;
    //         return;
    //     }
    //     Node *temp = head;
    //     while (temp != NULL)
    //     {
    //         if (temp->data == val && temp == head)
    //         {
    //             Deletefromfront();
    //             found = true;
    //             temp = temp->next;
    //         }
    //         else if (temp->data == val && temp == tail)
    //         {
    //             Deletefromlast();
    //             found = true;

    //             temp = temp->next;
    //         }
    //         else if (temp->data == val)
    //         {
    //             Node *del = temp;
    //             temp->prev->next = temp->next;
    //             temp->next->prev = temp->prev;
    //             temp = temp->next;
    //             delete del;
    //             found = true;
    //         }
    //         else
    //         {
    //             temp = temp->next;
    //         }
    //     }
    //     if (found == false)
    //     {
    //         cout << "Value is not in the list!!!" << endl;
    //         return;
    //     }
    // }
};
void Merge(Linklist l1, Linklist l2)
{
    // cout << "First head is " << l1.head->data << endl;
    // cout << "Second tail is " << l2.tail->data << endl;
    l1.tail->next = l2.head;
    l2.head->prev = l1.tail;
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
    Linklist l1;
    Linklist l2;
    l2.insertatlast(7);
    l2.insertatlast(8);
    l1.insertatlast(5);
    l1.InsertatFront(4);
    l1.Insetatanywhere(0, 3);
    l1.insertatlast(3);
    // l1.Displayheadtotail();
    // l1.ReverseList();
    // l1.Deletewithvalue(5);
    // l1.Displaytailtohead();
    //  Merge(l1, l2);
    // l1.Deletefromfront();
    // l1.deletefromanywhere(1);
    // l1.Display();
    // l1.Counter();
    l1.Displayheadtotail();
    l1.deleteallval(3);
    l1.Displayheadtotail();
}