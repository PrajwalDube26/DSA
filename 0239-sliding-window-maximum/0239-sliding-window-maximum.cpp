class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;

        while(j<nums.size())
        {
            pq.push({nums[j],j});
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                ans.push_back(pq.top().first);

                while(pq.top().second<=i)
                {
                    pq.pop();
                    if(pq.empty())
                    {
                        break;
                    }
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};