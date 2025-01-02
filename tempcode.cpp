#include<iostream>
using namespace std;
int main()
{
    int n,space,spacen,in;
    cout<<"Enter : ";
    cin>>n;
    spacen = n;
    in = n;
    for(int i = 1; i <= in; i++)
    {
        space = spacen - i;
        for(int j = 1; j <= n; j++)
        {
            if(space > 0)
            {
                cout<<" ";
                space--;
            }
            else
            {
                cout<<"*";
            }


        }
        n++;
        cout<<endl;
    }
}