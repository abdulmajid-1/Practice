#include<iostream>
using namespace std;

class Node 
{
    public:
 //   int top;
    Node *next;
    Node *prev;
    char data;
    Node(char d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class Stack
{
    public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void Push(char d)
    {

        Node *n_node = new Node(d);
        if(top == NULL)
        {
            top = n_node;
            return;
        }
        n_node -> next = top;
        top -> prev = n_node;
        top = n_node;
    }
    void Push(int d)
    {

        Node *n_node = new Node(d);
        if(top == NULL)
        {
            top = n_node;
            return;
        }
        n_node -> next = top;
        top -> prev = n_node;
        top = n_node;
    }

    char Pop()
    {
        if(top == NULL)
        {
            cout<<"empty !!! "<<endl;
        }
        else
        {
            Node *temp = top;
            top = top -> next;
            return temp -> data;
        }
        return ' ';
    }

    void Display()
    {
        if(top == NULL)
        {
            cout<<"Empty !!!"<<endl;
            return;
        }
        Node *temp = top;
        while(temp != NULL)
        {
            cout<< temp -> data << endl;
            temp = temp -> next;
        }
    }
    bool IsEmpty() 
    {
        if(top == NULL)
        {
            return true;
        }
        
        return top;
    }
   
  
};
bool Checkforpara(const string& s) 
{
    Stack s1;

    for (char ch : s) 
    {
        if (ch == '{' || ch == '[' || ch == '(') 
        {
            s1.Push(ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') 
        {
            if (s1.top == NULL) 
            {
                return false; // No matching opening bracket
            }

            char top = s1.Pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) 
            {
                return false; // Mismatched pair
            }
        }
    }

    return s1.IsEmpty(); // Check if all opening brackets are matched
}
int Postfix(string s)
{
    Stack s1;
    for(char ch : s)
    {
        if(ch == '*' || ch == '+' || ch == '-' || ch == '/')
        {
            if(ch == '*')
            {
                int var = s1.Pop();
                int var2 = s1.Pop();
                var = var * var2;
                s1.Push(var);
            }
            if(ch == '/')
            {
                int var = s1.Pop();
                int var2 = s1.Pop();
                var = var / var2;
                s1.Push(var);
            }
            if(ch == '+')
            {
                int var = s1.Pop();
                int var2 = s1.Pop();
                var = var + var2;
                s1.Push(var);
            }
            if(ch == '-')
            {
                int var2 = s1.Pop();
                int var = s1.Pop();
                var = var - var2;
                s1.Push(var);
            }
        
             
        }
        else
        {
            s1.Push(ch - '0');
        }
        
        
    }
    return s1.top ->data;
}

  
int main()
{
    Stack s1;
    string s = "23*54*+9-";
    int result = Postfix(s);
    cout<<"Expression is : "<<s<<endl;
    if (result != 0) 
    {
        cout << "Result: " << result << endl;
    }
    // string st1 = "{({)}";
    // string st2 = "()(){}";
    // bool checker;
    // cout<<"First string : "<<st1<<endl;
    // cout<<"Second string : "<<st2<<endl;
    // checker = Checkforpara(st1);
    // if(checker)
    // {
    //     cout<<"first Balanced "<<endl;
    // }
    // else
    // {
    //     cout<<"first Not Balanced "<<endl;
    // }
    // checker = Checkforpara(st2);
    // if(checker)
    // {
    //     cout<<"Second Balanced : "<<endl;
    // }
    // else
    // {
    //     cout<<"second not balanced "<<endl;
    // }




}