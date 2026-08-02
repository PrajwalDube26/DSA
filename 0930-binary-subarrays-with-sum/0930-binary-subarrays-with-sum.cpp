class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m1;
        int sum=0,ans=0;
        m1[0]=1;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            int oldprefix = sum-goal;
            if(m1.find(oldprefix)!=m1.end())
            {
                ans+=m1[oldprefix];
            }

            m1[sum]++;
        }

        return ans;
    }
};