class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>>s1;
        s1.push({nums[0],0});

        vector<int>ans(nums.size(),-1);

        for(int i=1;i<nums.size();i++)
        {
            while(!s1.empty() && nums[i]>s1.top().first)
            {
                ans[s1.top().second] = nums[i];
                s1.pop();
            }

            s1.push({nums[i],i});
        }

        for(int i=0;i<nums.size();i++)
        {
            while(!s1.empty() && nums[i]>s1.top().first)
            {
                ans[s1.top().second] = nums[i];
                s1.pop();
            }
        }

        return ans;
    }
};