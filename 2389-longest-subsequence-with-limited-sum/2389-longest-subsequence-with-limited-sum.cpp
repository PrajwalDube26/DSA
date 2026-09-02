class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n=nums.size();
        int m=queries.size();

        sort(nums.begin(),nums.end());

        vector<int>sum(n);
        int total=0;

        for(int i=0;i<n;i++)
        {
            total+=nums[i];
            sum[i]=total;
        }

        vector<int>ans(m);
        
        for(int i=0;i<m;i++)
        {
            int low=0,high=n-1;
            int ans_to_push=0;

            while(low<=high)
            {
                int mid = ((high-low)/2) + low;

                if(sum[mid]==queries[i])
                {
                    ans_to_push = mid+1;  //due to 0 based indexing
                    break;
                }
                else if(sum[mid]<queries[i])
                {
                    ans_to_push = mid+1;
                    low=mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            ans[i] = ans_to_push;
        }

        return ans;
    }
};