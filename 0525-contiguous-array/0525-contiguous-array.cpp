class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0,maxa=0;
        unordered_map<int,int>m1;
        m1[0]=-1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                sum+=-1;
            }
            else if(nums[i]==1)
            {
                sum+=1;
            }

            int oldprefix = sum-0;
            if(m1.find(sum)!=m1.end())
            {
                maxa = max(maxa , i-m1[sum]);
            }
            else
            {
                m1[sum]=i;
            }
        }

        return maxa;
    }
};