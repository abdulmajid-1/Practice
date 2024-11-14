#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> nums = {0,4,3,5,3,-34,4,9,0};
            int cs = 0, ms = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            cs += nums[i];
            ms = max(cs,ms);
            if(cs < 0)
            {
                cs = 0;
            }
           
        }
       cout<<ms<<endl<<nums.size()<<endl;
    }
