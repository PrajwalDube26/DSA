class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        vector<int>v1; 
        map<int,int>m1;
        for(int i=0;i<nums.size();i++)
        {
            m1[nums[i]]++;
        }

        for(auto ch:m1)
        {
            if(ch.second>n)
            {
                v1.push_back(ch.first);
            }
        }

        return v1;
    }
};