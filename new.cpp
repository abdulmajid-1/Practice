#include <iostream>
using namespace std;

class Stack
{
    int *stack;
    int top;
    int n = 5;
    public:
    Stack()
    {
        stack = new int[n];
        top = -1;
    }
    void Push(int x)
    {
        if (n > (top + 1))
        {
            top++;
            stack[top] = x;
        }
        else
        {
            cout << "Stack is full !!!" << endl;
        }
    }
    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty !!!" << endl;
        }
        else
        {
            top--;
        }
    }
    int Peak()
    {
        return stack[top];
    }
};
int main()
{    
    Stack s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    cout<<s1.Peak()<<" ";
    s1.Pop();
    cout<<s1.Peak()<<" ";
    s1.Pop();
    cout<<s1.Peak()<<" ";
    s1.Pop();
    s1.Push(4);
    cout<<s1.Peak()<<" ";
    s1.Pop();
    cout<<endl;
}