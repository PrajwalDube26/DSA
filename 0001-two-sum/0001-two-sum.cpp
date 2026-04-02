class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> two;
        bool m=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    two.push_back(i);
                    two.push_back(j);
                    m=1;
                    break;
                }
            }
            if(m)
            {
                break;
            }
        }

        return two;
    }
};