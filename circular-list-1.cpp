// Circular Linked List (CLL)
// ⦁	Implement a basic circular linked list with insert at the beginning, insert at the end, and delete operations.
// ⦁	Implement a traversal function that starts from the head and loops around back to the head
// ⦁	Implement the delete operation to remove a specific node in a circular linked list by value or position
// ⦁	Write a function to reverse the circular linked list (circularity must be maintained).

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
class Linklist
{
    Node *head;
    Node *tail;
    public:
       Linklist()
        {
            head = tail = NULL;
        }
        
};
