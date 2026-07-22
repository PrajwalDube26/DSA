class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v1(256,0);
        int maxa = 0;
        int left=0;

        for(int right=0;right<s.length();right++)
        {
            bool z=0;
            if(v1[s[right]]==0)
            {
                v1[s[right]]=1;
            }
            else if(v1[s[right]]==1)
            {
                z=1;
                right--;
            }

            if(z==1)
            {
                v1[s[left]]=0;
                left++;
            }
            maxa = max(maxa,right-left+1);
        }

        return maxa;
    }
};