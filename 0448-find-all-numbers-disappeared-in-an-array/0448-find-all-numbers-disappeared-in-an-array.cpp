class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>pres(nums.size(),0);

        for(int i=0;i<nums.size();i++)
        {
            pres[nums[i]-1]=1;
        }

        vector<int>ans;

        for(int i=0;i<pres.size();i++)
        {
            if(pres[i]==0)
            {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};