class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m1;
        m1[0]=-1;
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            int oldprefix = sum % k;
            if(m1.find(oldprefix)!=m1.end())
            {
                if(i-m1[oldprefix] >=2 )
                {
                    return true;
                }
            }
            else
            {
                m1[sum % k]=i;
            }
        }
        return false;
    }
};