#include<iostream>
using namespace std;

class Node 
{
    public:
        int pcode;
        float price;
        string name;
        Node *left;
        Node *right;
        Node(int p,string n, float pri)
        {
            pcode = p;
            name = name ;
            price = pri;
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
        void insertnode(int p, string n, float pri)
        {
            Node *n_node = new Node(p,n,pri);
            if(root == NULL)
            {
                root = n_node;
                return;
            }
            Node *temp = root;
            while(temp)
            {
                if(n_node -> price < temp -> price)
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
                if(n_node ->price > temp -> price)
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
                if(temp -> price == temp -> price)
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
                cout<<root -> price <<" ";
                cout<<root -> name<<" ";
                cout<<root -> pcode<<" ";
                inorderdisplay(root -> right);
                cout<<endl;
            }
        }
        void preorder(Node *root)
        {
            if(root != NULL)
            {
                cout<<root -> price<<" ";
                cout<<root -> name<<" ";
                cout<<root -> pcode<<" ";
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
                cout<<root -> price<<" ";
                cout<<root -> name<<" ";
                cout<<root -> pcode<<" ";
                cout<<endl;
            }
        }
        void search(int key, Node *root)
        {
           while(root != NULL)
           {
                if(key == root ->price)
                {
                    cout<<"Data found "<<endl;
                    return;
                }
                else if(key > root -> price)
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
            while(root -> right != NULL)
            {
                root = root -> right;
            }
            cout<<"Max price is : "<<root -> price<<endl;


        }
        void minnode(Node *root)
        {
            while(root -> left != NULL)
            {
                root = root -> left;
            }
            cout<<"Max price is : "<<root -> price<<endl;


        }
        


};
int main()
{
    Tree t1;
    t1.insertnode(111,"oil",1000);
    t1.insertnode(222,"roti",2000);
    t1.insertnode(333,"shampoo",3000);
    cout<<"Inorder display \n";
    t1.inorderdisplay(t1.root);
    cout<<"Preorder display \n";
    t1.preorder(t1.root);
    cout<<"Postorder display \n";
    t1.postorder(t1.root);
    // t1.maxnode(t1.root);
    // t1.minnode(t1.root);
    



}