#include<iostream>
using namespace std;
int main()
{
    int arr[] = {2,3,4,4,3,2,6};
    int size = 7;
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        result = result ^ arr[i];
    }
    cout<<result<<endl;
}