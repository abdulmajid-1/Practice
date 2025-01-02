#include<iostream>
using namespace std;

class Node 
{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d)
        {
            data = d;
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
        void insertnode(int d)
        {
            Node *n_node = new Node(d);
            if(root == NULL)
            {
                root = n_node;
                return;
            }
            Node *temp = root;
            while(temp)
            {
                if(n_node -> data < temp -> data)
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
                if(n_node ->data > temp -> data)
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
                if(temp -> data == temp -> data)
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
                cout<<root -> data <<" ";
                inorderdisplay(root -> right);
                cout<<endl;
            }
        }
        void preorder(Node *root)
        {
            if(root != NULL)
            {
                cout<<root -> data<<" ";
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
                cout<<root -> data<<" ";
                cout<<endl;
            }
        }
        void search(int key, Node *root)
        {
           while(root != NULL)
           {
                if(key == root ->data)
                {
                    cout<<"Data found "<<endl;
                    return;
                }
                else if(key > root -> data)
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
            cout<<"Max node is : "<<root -> data<<endl;


        }
        void minnode(Node *root)
        {
            while(root -> right != NULL)
            {
                root = root -> right;
            }
            cout<<"Max node is : "<<root -> data<<endl;


        }
        


};
int main()
{
    Tree t1;
    t1.insertnode(10);
    t1.insertnode(5);
    t1.insertnode(20);
    // cout<<"Inorder display \n";
    // t1.inorderdisplay(t1.root);
    // cout<<"Preorder display \n";
    // t1.preorder(t1.root);
    // cout<<"Postorder display \n";
    // t1.postorder(t1.root);
    t1.maxnode(t1.root);
    t1.minnode(t1.root);
    



}