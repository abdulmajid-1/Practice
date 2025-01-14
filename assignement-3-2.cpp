#include<iostream>
using namespace std;

struct List
{
    string names;
    List *next = NULL;
};
class Node
{
    public:
        Node *left;
        Node *right;
        int rating;
        string title;
        List *Authors;
        Node(string name, int rat)
        {
            title = name;
            rating = rat;
            left = NULL;
            right = NULL;  
            Authors = NULL;      
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
        List* getauthers(string name)
        {
            char c = 'y';
            string n;
            bool condition = true;
            List *temp_node = NULL;
         
           
            while(c == 'y')
            {
                List *n_name = new List;
                cout<<"Enter auther of "<<name<<" : ";
                cin>>n_name -> names;
                if(condition)
                {
                    temp_node = n_name;
                    condition = false;
                }
                else
                {
                    temp_node -> next = n_name;
                }
              
                cout<<"do you want to add another author (y/n): "<<endl;
                cin>>c;
            }
            return temp_node;

        }
        // void show_books(Node *root, int rat)
        // {
        //     if(root != NULL)
        //     {
        //         if(root -> rating >= rat)
        //         {
        //             cout<<"Book title : "<<root ->title<<endl;
        //             cout<<"Book rating : "<<root -> rating <<endl;
        //             cout<<"Book authors : "<<endl;
        //             List *t = root -> Authors;
        //             while(t)
        //             {
        //                 cout<<t ->names<<endl;
        //                 t = t -> next;
        //             }
        //             show_books(root -> left, rat);
        //             show_books(root -> right, rat);
        //             cout<<endl;
        //         }
        //     }
        // }
        void show_books(Node *root, int rat)
        {
            if (root != NULL)
            {
            // Check if the rating meets or exceeds the parameter
                if (root->rating >= rat)
                {
                    cout << "Book title : " << root->title << endl;
                    cout << "Book rating : " << root->rating << endl;
                    cout << "Book authors : " << endl;

                    List *t = root->Authors;
                    while (t)
                    {
                        cout << t->names << endl;
                        t = t->next;
                    }
                    cout << endl;
                }

            // Continue to traverse the tree
                show_books(root->left, rat);
                show_books(root->right, rat);
            }
        }

        void Insertbook(string name, int rat)
        {
            Node *n_node = new Node(name,rat);
            n_node -> Authors = getauthers(name);

            if(!root)
            {
                root = n_node;
                return;
            }
            Node *temp = root;
            while(temp)
            {
                if(n_node -> rating > temp -> rating)
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
                if(n_node -> rating < temp -> rating)
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
                if(temp -> rating == n_node -> rating)
                {
                    return;
                }
            }
        }
       
};
int main()
{
    Tree t1;
    t1.Insertbook("song of ice and fire",10);
    t1.Insertbook("crime and punishment",8);
    t1.Insertbook("Art of war",9);
    t1.show_books(t1.root , 9);

}
