class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum=0,ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            sum=0;
            int j=max(0,i-nums[i]);
            for(j;j<=i;j++)
            {
                sum+=nums[j];
            }
            ans+=sum;
        }

        return ans;
    }
};