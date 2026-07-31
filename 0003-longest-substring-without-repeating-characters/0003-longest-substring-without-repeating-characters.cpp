class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v1(256,0);
        int n=s.length();
        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int k=0;k<256;k++)
            {
                v1[k]=0;
            }
            for(int j=i;j<n;j++)
            {
                if(v1[s[j]]==0)
                {
                    v1[s[j]]++;
                    count = max(count,j-i+1);
                }
                else
                {
                    break;
                }
            }
        }

        return count;
    }
};