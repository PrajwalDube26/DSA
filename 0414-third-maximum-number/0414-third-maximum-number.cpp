class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long maxa=LLONG_MIN,smaxa=LLONG_MIN,tmaxa=LLONG_MIN;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxa)
            {
                long long temp1=maxa,temp2=smaxa;
                maxa=nums[i];
                smaxa=temp1;
                tmaxa=temp2;
            }
            else if(nums[i]<maxa && nums[i]>smaxa)
            {
                long long temp1=smaxa;
                smaxa=nums[i];
                tmaxa=temp1;
            }
            else if(nums[i]<smaxa && nums[i]>tmaxa)
            {
                tmaxa=nums[i];
            }
        }

        if(tmaxa==LLONG_MIN)
        {
            return maxa;
        }

        return tmaxa;
    }
};