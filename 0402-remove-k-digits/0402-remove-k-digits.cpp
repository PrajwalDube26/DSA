class Solution {
public:
    string reverse(string & ans, int n)
    {
        for(int i=0;i<n/2;i++)
        {
            swap(ans[i],ans[n-1-i]);
        }
        return ans;
    }


    string removeKdigits(string num, int k) {
        if(k>=num.length())
        {
            return "0";
        }

        stack<char>s1;
        string ans="",ans2="";

        s1.push(num[0]);

        for(int i=1;i<num.length();i++)
        {
            while(!s1.empty() && s1.top()-'0' > num[i] - '0' && k>0)
            {
                s1.pop();
                k--;
            }
            s1.push(num[i]);
        }

        while(k>0)
        {
            s1.pop();
            k--;
        }

        while(!s1.empty())
        {
            ans.push_back(s1.top());
            s1.pop();
        }

        string ansr = reverse(ans,ans.length());

        int z=0;
        if(ansr!="" && ansr[0]=='0')
        {
            for(int i=0;i<ansr.size();i++)
            {
                if(ansr[i]-'0' !=0)
                {
                    break;
                }
                z++;
            }

            for(int i=z;i<ansr.size();i++)
            {
                ans2=ans2 + ansr[i];
            }
        }
        else
        {
            ans2=ansr;
        }

        if(ans2=="")
        {
            return "0";
        }
        return ans2;


    }
};