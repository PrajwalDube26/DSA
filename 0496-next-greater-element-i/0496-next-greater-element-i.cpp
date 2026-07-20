class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>um;
        stack<int>s1;
        s1.push(nums2[0]);

        for(int i=1;i<nums2.size();i++)
        {
            while(!s1.empty() && s1.top()<nums2[i])
            {
                um[s1.top()] = nums2[i];
                s1.pop();
            }
            s1.push(nums2[i]);
        }

        while(!s1.empty())
        {
            um[s1.top()] = -1;
            s1.pop();
        }

        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            auto it = um.find(nums1[i]);
            if(it != um.end())
            {
                ans[i] = it->second;
            }
        }

        return ans;
    }
};