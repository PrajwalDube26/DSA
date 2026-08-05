class Solution {
public:
    int AtMost(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int right=0,left=0;
        int count=0,ans=0;

        for(right=0;right<n;right++)
        {
            if(nums[right]%2==1)
            {
                count++;
            }

            while(count>k)
            {
                if(nums[left]%2==1)
                {
                    count--;
                }

                left++;
            }

            ans+=right-left+1;
        }

        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return AtMost(nums,k) - AtMost(nums,k-1);
    }
};