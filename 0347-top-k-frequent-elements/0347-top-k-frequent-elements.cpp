class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        int n = nums.size();
        priority_queue<pair<int,int>>pq;
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            um[nums[i]]++;
        }

        for(auto it:um)
        {
            pq.push({it.second,it.first});
        }

        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};