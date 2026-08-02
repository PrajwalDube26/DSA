class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n= nums.size();
        unordered_map<int,int>m1;
        m1[0]=1;
        int sum=0,count=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            int oldprefix = ((sum % k) + k)%k;
            if(m1.find(oldprefix)!=m1.end())
            {
                count+=m1[oldprefix];
            }

            m1[((sum % k) + k)%k]++;
        }

        return count;
    }
};