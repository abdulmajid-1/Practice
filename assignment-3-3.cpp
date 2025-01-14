#include<iostream>
#include<queue>
using namespace std;

class Node 
{
    public:
    string name;
    int age;
    string relation;
    Node *left;
    Node *right;
    Node(string n, int a)
    {
        age = a;
        name = n;
        right = NULL;
        left = NULL;
    }

};
class Tree
{
    public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void insertnode(string n, int a)
        {
            Node *n_node = new Node(n, a);
            if(root == NULL)
            {
                root = n_node;
                return;
            }
            Node *temp = root;
            while(temp)
            {
                if(n_node -> age > temp -> age)
                {
                    if(temp -> right == NULL)
                    {
                        temp -> right = n_node;
                        return;
                    }
                    else
                    {
                        temp = temp -> right;
                    }
                 
                }
                if(n_node ->age < temp -> age)
                {
                    if(temp -> left == NULL)
                    {
                        temp -> left = n_node;
                        return;

                    }
                    else
                    {
                        temp = temp -> left;
                    }
                }
                if(temp -> age == n_node -> age)
                {
                    return;
                }
            }

        }
        void preorder(Node *root, string n)
        {
            if(root != NULL)
            {
            
                preorder(root -> left, n);
                preorder(root -> right, n);
                cout<<endl;
            }
        }
        void findchildren(string n)
        {

        }
  
};
int main()
{
    Tree t1;

}