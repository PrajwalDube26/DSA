class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>us;
        int n=nums.size();

        for(int i=0;i<min(n,k);i++)
        {
            if(us.find(nums[i])!=us.end())
            {
                return 1;
            }
            else
            {
                us.insert(nums[i]);
            }
        }

        if(k>n)return 0;

        int left=0,right=k;

        for(right=k;right<n;right++)
        {
            if(us.find(nums[right])!=us.end())
            {
                return 1;
            }
            else
            {
                us.insert(nums[right]);
                us.erase(nums[left]);
                left++;
            }
        }

        return 0;
    }
};