#include<iostream>
using namespace std;

class Solution 
{
public:
    int maxDepth(string s) 
    {
        int count=0,i=0;
        char A[100];

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

        for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
        {
           for(int j=0;j<(sizeof(A)/sizeof(A[0]))-1;j++)
           {
               if(A[j]<A[j+1])
               {
                  swap(A[j],A[j+1]);
               }
           }
        }
        return A[0];
        
    }
};

