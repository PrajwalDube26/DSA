class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int j=0;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                if(count!=0)
                {
                    s[j]=s[i];
                    j++;
                }
                count++;
            }
            else if(s[i]==')')
            {
                count--;
                if(count!=0)
                {
                    s[j]=s[i];
                    j++;
                }
            }
        }

        s.resize(j);
        return s;
    }
};