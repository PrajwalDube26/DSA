#include<iostream>
using namespace std;

class Solution 
{
public:
    int maxDepth(string s) 
    {
        int count=0,i=0;
        int A[100];

        for(char c:s)
        {
            if(c=='(')
            {
                count++;

            }
            else if(c==')')
            {
                A[i++]=count;
                count--;
            }
        }

        int ans=0;

        for(int j=0;j<i;j++)
        {
            ans = max(ans,A[j]);
        }

        return ans;
        
    }
};

