class Solution {
public:
    int AtMost(vector<int>& nums, int goal) 
    {
        if(goal<0)
        {
            return 0;
        }

        int n=nums.size();
        int right=0,left=0;
        int count=0,ans=0;

        for(right=0;right<n;right++)
        {
            count+=nums[right];

            while(count>goal)
            {
                count-=nums[left];
                left++;
            }

            ans+=right-left+1;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return AtMost(nums,goal) - AtMost(nums,goal-1);
    }
};