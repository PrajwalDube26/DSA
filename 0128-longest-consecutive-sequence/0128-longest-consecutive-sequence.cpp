class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m1;
        int n=nums.size();
        int m=0,a,count=0,maxa=0;

        for(int i=0;i<n;i++)
        {
            m1[nums[i]]++;
        }

        for(auto it:m1)
        {
            if(m==0)
            {
                count=1;
                m=1;
                a=it.first;
                maxa = max(maxa,count);
                continue;
            }

            if(it.first == a+1)
            {
                count++;
            }
            else
            {
                count=1;
            }

            a=it.first;
            maxa = max(maxa,count);

        }
        return maxa;
    }
};