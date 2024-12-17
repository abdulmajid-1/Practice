#include<iostream>
using namespace std;
class Node
{
    public:
        int id;
        Node *next;
        Node *prev;
        Node(int i)
        {
            id = i;
            next = NULL;
            prev = NULL;
        }
};
class Linklist
{
    Node *head;
    public:
    
    void swaping(int m, int n)
    {
        if(head = NULL)
        {
            cout<<"Empty"<<endl;
            return;
        }
        Node *n_temp = head;
        Node *m_temp = head;
        Node *current_temp;
        for(int i = 0; i < m; i++)
        {
            for(int i = 0; i < n; i++)
            {
                n_temp = n_temp -> next;
            }
            current_temp = m_temp -> next;
            m_temp -> next = n_temp -> next;
            current_temp -> next = m_temp;
            n_temp -> next = current_temp;


            // move mth node
            m_temp = m_temp -> next;
        }

    }

};
int main()
{
    return 0;
}