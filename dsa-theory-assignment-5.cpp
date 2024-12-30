#include <iostream>
#define SIZE 5
using namespace std;

class Queue
{
    int q[SIZE];
    int in, out;
    bool isempty, isfull;

public:
    Queue()
    {
        for (int i = 0; i < SIZE; i++)
        {
            q[i] = 0;
        }
        in = 0;
        out = 0;
        isempty = 1;
        isfull = 0;
    }
    void increament(int &in)
    {
        if (in >= (SIZE - 1))
        {
            in = 0;
        }
        else
        {
            in++;
        }
    }
    void enqueue(int data)
    {
        if (isfull)
        {
            cout << "Queue is full!!!" << endl;
            return;
        }
        else
        {

            q[in] = data;
            increament(in);
            isempty = 0;
            if (in == out)
            {
                isfull = 1;
            }
        }
    }
    int dequeue()
    {
        int temp;
        if (isempty)
        {
            cout << "Empty Queue!!!" << endl;
            return -1;
        }
        else
        {

            temp = q[out];
            increament(out);
            isfull = 0;
            if (in == out)
            {
                isempty = 1;
            }

            return temp;
        }
    }
    void print()
    {

        for (int i = 0; i < SIZE; i++)
            cout << q[i] << " ";

        cout << endl;
    }
};
int main()
{
    Queue q1;
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.print();
    q1.enqueue(88);
    q1.dequeue();
    q1.enqueue(99);
    q1.print();
}