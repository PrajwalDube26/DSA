class Solution {
public:

    int AtMost(vector<int>& nums, int k)
    {
        unordered_map<int,int>m1;;
        int left=0,right=0;
        int n=nums.size();
        int ans=0;
        
        for(right=0;right<n;right++)
        {
            m1[nums[right]]++;
            
            while(m1.size()>k)
            {
                m1[nums[left]]--;

                if(m1[nums[left]]==0)
                {
                    m1.erase(nums[left]);
                }
                
                left++;
            }
            
            ans+=right-left+1;
        }
        
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return AtMost(nums,k) - AtMost(nums,k-1);
    }
};