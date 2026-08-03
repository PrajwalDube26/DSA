class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>m1;
        int n=nums.size();
        int m=0,a,count=0,maxa=0;

        for(int i=0;i<n;i++)
        {
            m1.insert(nums[i]);
        }

        for(auto it:m1)
        {
            if(m==0)
            {
                count=1;
                m=1;
                a=it;
                maxa = max(maxa,count);
                continue;
            }

            if(it == a+1)
            {
                count++;
            }
            else
            {
                count=1;
            }

            a=it;
            maxa = max(maxa,count);

        }
        return maxa;
    }
};