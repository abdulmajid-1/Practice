#include <iostream>
using namespace std;

class Node {
public:
    int pcode;
    float price;
    string name;
    Node *left;
    Node *right;

    Node(int p, string n, float pri) {
        pcode = p;
        name = n;
        price = pri;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node *root;

    Tree() {
        root = NULL;
    }

    void insertnode(int p, string n, float pri) {
        Node *n_node = new Node(p, n, pri);
        if (root == NULL) {
            root = n_node;
            return;
        }
        Node *temp = root;
        while (true) {
            if (n_node->price < temp->price) {
                if (temp->left == NULL) {
                    temp->left = n_node;
                    return;
                }
                temp = temp->left;
            } else if (n_node->price > temp->price) {
                if (temp->right == NULL) {
                    temp->right = n_node;
                    return;
                }
                temp = temp->right;
            } else {
                // Duplicate prices are not allowed
                return;
            }
        }
    }

    void inorderdisplay(Node *root) {
        if (root != NULL) {
            inorderdisplay(root->left);
            cout << "Price: " << root->price << ", Name: " << root->name << ", PCode: " << root->pcode << endl;
            inorderdisplay(root->right);
        }
    }

    void preorder(Node *root) {
        if (root != NULL) {
            cout << "Price: " << root->price << ", Name: " << root->name << ", PCode: " << root->pcode << endl;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << "Price: " << root->price << ", Name: " << root->name << ", PCode: " << root->pcode << endl;
        }
    }

    void search(float key, Node *root) {
        while (root != NULL) {
            if (key == root->price) {
                cout << "Data found: Price = " << root->price << ", Name = " << root->name << ", PCode = " << root->pcode << endl;
                return;
            } else if (key < root->price) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        cout << "Data not found." << endl;
    }

    void maxnode(Node *root) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }
        while (root->right != NULL) {
            root = root->right;
        }
        cout << "Max price is: " << root->price << ", Name: " << root->name << ", PCode: " << root->pcode << endl;
    }

    void minnode(Node *root) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }
        while (root->left != NULL) {
            root = root->left;
        }
        cout << "Min price is: " << root->price << ", Name: " << root->name << ", PCode: " << root->pcode << endl;
    }
};

int main() {
    Tree t1;
    char choice = 'y';
    int intchoice;
    string productname;
    float price;
    int productcode;
    while(choice == 'y')
    {
        cout<<"Enter the product name : "<<endl;
        cin>>productname;
        cout<<"Enter the product price : "<<endl;
        cin>>price;
        cout<<"Enter the product code : "<<endl;
        cin>>productcode;
        t1.insertnode(productcode,productname,price);
        cout<<"\nDo you want to continue (y/n) : "<<endl;
        cin>>choice;
    }
    cout<<"1)Inorderdisplay\n2)Postorderdisplay\n3)preorderdisplay\n";
    cout<<"Which type of display you want : (1,2,3) "<<endl;
    cin>>intchoice;

    if(intchoice == 1)
    {
        t1.inorderdisplay(t1.root);
        cout<<endl;
    }
    else if(intchoice == 2)
    {
        t1.postorder(t1.root);
        cout<<endl;
    }
    else if(intchoice == 3)
    {
        t1.preorder(t1.root);
        cout<<endl;
    }
    else
    {
        cout<<"Wrong index "<<endl;
    }

    return 0;
}
