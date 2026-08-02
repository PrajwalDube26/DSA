class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>m1;
        int count=0,ans=0;
        m1[0]=1;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==1)
            {
                count++;
            }

            int oldprefix = count-k;
            if(m1.find(oldprefix)!=m1.end())
            {
                ans+=m1[oldprefix];
            }

            m1[count]++;
        }

        return ans;
    }
};