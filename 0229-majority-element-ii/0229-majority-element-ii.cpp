class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=int(nums.size() / 3) + 1;;
        vector<int>v1; 
        unordered_map<int,int>m1;
        for(int i=0;i<nums.size();i++)
        {
            m1[nums[i]]++;
            
            if(m1[nums[i]] == n)
            {
                v1.push_back(nums[i]);
            }

            if(v1.size()==2)
            {
                break;
            }
        }

        return v1;
    }
};