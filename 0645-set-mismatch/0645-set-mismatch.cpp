class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>s1;
        vector<int>ans(2);
        int n = nums.size(),real_sum=0;
        int excep_sum=(n*(n+1))/2;
        int repeted;

        for(int i=0;i<n;i++)
        {
            
            if(s1.find(nums[i]) != s1.end())
            {
                repeted = nums[i];
            }
            else
            {
                s1.insert(nums[i]);
                real_sum+=nums[i];
            }   
        }

        ans[0]=repeted;
        ans[1] = excep_sum - real_sum;

        return ans;
    }
};