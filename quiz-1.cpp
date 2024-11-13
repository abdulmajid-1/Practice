#include<iostream>
using namespace std;
int main()
{
    int arr[5] = {2,3,4,5,6};
    int *p;
    p = arr;
    cout<<"Data original : "<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"Modified data : "<<endl;
    for(int i = 0; i < 5; i++)
    {
        p[i] *= 10;
    }
    for(int i = 0; i < 5; i++)
    {
        cout<<*(p + i)<<" ";
    }
    cout<<endl;
}