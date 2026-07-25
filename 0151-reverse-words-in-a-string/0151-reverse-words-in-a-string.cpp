class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int count=0;
        int i = s.length()-1;
        while(s[i]==' ')
        {
            i--;
        }

        int end=i;
        for(i;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                count++;
            }
            else if(s[i]==' ')
            {
                if(count>0)
                {
                    ans +=s.substr(i+1,end-i); 
                    ans+=' ';
                }
                    
                count=0;
            }

            if(count==1)
            {
                end=i;
            }
        }

        if(count>0)
            ans +=s.substr(0,end+1);
        else if(count==0)
        {
            ans = ans.substr(0,ans.length()-1);
        }
        return ans;
    }
};