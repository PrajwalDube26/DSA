class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s1;
        int n=nums.size();
        int count=0,maxa=0;

        for(int i=0;i<n;i++)
        {
            s1.insert(nums[i]);
        }

        for(auto it:s1)
        {
            int a=it;
            if(s1.find(a-1)==s1.end())
            {
                count=1;

                while(s1.find(a+1)!=s1.end())
                {
                    count++;
                    a++;
                }

                maxa = max(maxa,count);

            }
            
        }
        return maxa;
    }
};