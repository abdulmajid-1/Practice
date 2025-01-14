#include<iostream>
using namespace std;

class Node 
{
    public:
        int ID;
        string name;
        float gpa;
        Node *left;
        Node *right;
    
        Node(int id, string n, float g)
        {
            ID = id;
            gpa = g;
            name = n;
            left = NULL;
            right = NULL;

        }
};
class Tree
{
    public:
        Node * root;
        Tree()
        {
            root = NULL;
        }
        void insertnode(int id, string n, float g)
        {
            Node *n_node = new Node(id,n,g);
            if(root == NULL)
            {
                root = n_node;
                return;
            }
            Node *temp = root;
            while(temp)
            {
                if(n_node -> gpa < temp -> gpa)
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
                if(n_node ->gpa > temp -> gpa)
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
                if(temp -> gpa == temp -> gpa)
                {
                    return;
                }
            }

        }
        void inorderdisplay(Node *root)
        {
            if(root != NULL)
            {
                inorderdisplay(root -> left);
                cout<<root -> gpa <<" ";
                inorderdisplay(root -> right);
                cout<<endl;
            }

        }
        void preorder(Node *root)
        {
            if(root != NULL)
            {
                cout<<root -> gpa<<" ";
                preorder(root -> left);
                preorder(root -> right);
                cout<<endl;
            }
        }
        void postorder(Node *root)
        {
            if(root != NULL)
            {
                postorder(root -> left);
                postorder(root -> right);
                cout<<root -> gpa<<" ";
                cout<<endl;
            }
        }
        void search(int key, Node *root)
        {
           while(root != NULL)
           {
                if(key == root ->gpa)
                {
                    cout<<"Data found "<<endl;
                    return;
                }
                else if(key > root -> gpa)
                {
                    root = root -> right;

                }
                else
                {
                    root = root -> left;
                }
           }
           cout<<"Data not found "<<endl;
        }
        void maxnode(Node *root)
        {
            while(root -> left != NULL)
            {
                root = root -> left;
            }
            cout<<"Max gpa is : "<<root -> gpa<<endl;


        }
        void minnode(Node *root)
        {
            while(root -> right != NULL)
            {
                root = root -> right;
            }
            cout<<"Min gpa is : "<<root -> gpa<<endl;


        }
        


};
int main()
{
    Tree t1;
    t1.insertnode(946,"Majid",3.3);
    t1.insertnode(912,"Umer",3.2);
    t1.insertnode(933,"Haider",3.0);
    // cout<<"Inorder display \n";
    // t1.inorderdisplay(t1.root);
    // cout<<"Preorder display \n";
    // t1.preorder(t1.root);
    // cout<<"Postorder display \n";
    // t1.postorder(t1.root);
    t1.maxnode(t1.root);
    t1.minnode(t1.root);
    



}