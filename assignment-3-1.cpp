#include<iostream>
#include<queue>
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
                if(n_node -> data > temp -> data)
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
                if(n_node ->data < temp -> data)
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
                if(temp -> data == n_node -> data)
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
    void Leftviewt(Node *root)
    {
        if(!root)
            return;
        cout<<"Left view :"<<endl;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                Node *current = q.front();
                q.pop();
                if(i == 0)
                {
                    cout<<current -> data<<" ";
                }
                if(current -> left)
                    q.push(current -> left);

                if(current -> right)
                    q.push(current -> right);

            }

        }
    }
    void Levelorder(Node *root) 
    {
        if (!root)
            return;

        cout <<"Level order:" << endl;

        queue<Node*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) 
        {
            int size = q.size(); // Number of nodes at the current level
            cout << "Level " << level << " : ";
            for (int i = 0; i < size; i++) 
            {
                Node *current = q.front();
                q.pop();
                cout << current->data << " ";

            // Add the left and right children to the queue
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            level++;
            cout << endl;
        }
    }

            
    // void Leftviewoftree(Node *root) 
    // {
    //     if (root == NULL) 
    //     {
    //         return;
    //     }
    //     cout<<"Left view of the tree is : "<<endl;

    //     queue<Node*> q;
    //     q.push(root);

    //     while (!q.empty()) 
    //     {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) 
    //         {
    //             Node *current = q.front();
    //             q.pop();

    //             // Print the first node of each level
    //             if (i == 0) 
    //             {
    //                 cout << current->data << " ";
    //             }

    //             // Add the left and right children to the queue
    //             if (current->left) 
    //             {
    //                 q.push(current->left);
    //             }
    //             if (current->right) 
    //             {
    //                 q.push(current->right);
    //             }
    //         }
    //     }
    // }
};
int main()
{
    Tree t1;
    t1.insertnode(5);
    t1.insertnode(4);
    t1.insertnode(3);
    t1.insertnode(6);
    t1.insertnode(7);
    t1.insertnode(8);
    t1.insertnode(9);
    t1.insertnode(10);
    // t1.Leftviewt(t1.root);
    t1.Levelorder(t1.root);

}