class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0,start=0;
        string s1="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                balance++;
                if(balance==1)
                {
                    continue;
                }
            }
            else if(s[i]==')')
            {
                balance--;
                if(balance==0)
                {
                    continue;
                }
            }

            s1=s1+s[i];
            // if(balance==0)
            // {
            //     s1+=s.substr(start+1,i-start-1);
            //     start=i+1;
            // }
        }

        return s1;
    }
};