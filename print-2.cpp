#include<iostream>
using namespace std;
int main()
{
    int firstrow = 0;
    int lastrow = 6;
    int firstcol = 0;
    int lastcol = 6;
    int middlerow = 0;
    bool checker = 0;
    for(int i = 0; i < 6; i++)
    {
        if(middlerow == 3)
        {
            checker = 1;     
        }
        for(int j = 0; j < 6; j++)
        {
            if(checker == 1)
            {
                cout<<"*";
            }
            if(firstcol < 5 )
            {
                cout<<"*";
                firstcol++;
            }
            else if(j == 5 && middlerow < 3 )
            {
                cout<<"*";
                middlerow++;
            }
            // else if(middlerow > 3)
            // {
            //     checker = 1;
            // }
            else
            {
                cout<<" ";
            }
        
        }
        cout<<endl;
    }
}