class Solution {
public:
    int currentcount(string s)
    {
        int count=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                count++;
            }
        }

        return count;
    }
    int countRotations(string s, int k) 
    {
        int ans=0;

        int count=currentcount(s);

        if(count==k)ans++;

        int n=s.length();
        int right=0,left=n-1;

        for(right=0;right<n-1;right++)
        {
            if(s[right]==s[right+1])
            {
                count--;
            }

            if(s[left]==s[(left+1)%n])
            {
                count++;
            }
            left=(left+1)%n;

            if(count==k)ans++;
        }

        return ans;
    }
};