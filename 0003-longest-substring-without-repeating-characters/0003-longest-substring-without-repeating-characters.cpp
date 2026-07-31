class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int n=s.length();
        unordered_set<int>s1;
        int count=0;

        for(right=0;right<n;right++)
        {
            if(s1.find(s[right]) != s1.end())
            {
                while(s1.find(s[right]) != s1.end())
                {
                    s1.erase(s[left]);
                    left++;
                }

                s1.insert(s[right]);
            }
            else
            {
                s1.insert(s[right]);
            }

            count = max(count,right-left+1);
        }

        return count;
    }
};