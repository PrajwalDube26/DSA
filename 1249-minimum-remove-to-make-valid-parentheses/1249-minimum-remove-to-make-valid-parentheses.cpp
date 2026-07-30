class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n= s.length();
        string ans="";
        vector<int>to_delete(n,0);
        int bal=0,maxa=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                bal++;
            }
            else if(s[i]==')')
            {
                if(bal==0)
                {
                    to_delete[i]=1;
                }
                else
                {
                    bal--;
                }
            }
        }

        bal=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                if(bal==0)
                {
                    to_delete[i]=1;
                }
                else
                {
                    bal++;
                }
            }
            else if(s[i]==')')
            {
                bal--;
            }
        }

        int count=0;

        for(int i=0;i<n;i++)
        {
            if(to_delete[i])
            {
                s.erase(i-count,1);
                count++;
            }
        }

        return s;
    }
};