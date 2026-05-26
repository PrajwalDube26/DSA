class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxa_index=-1,maxa=INT_MIN,smaxa=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxa)
            {
                int temp=maxa;
                maxa=nums[i];
                maxa_index=i;
                smaxa=temp;
            }
            else if(nums[i]<maxa && nums[i]>smaxa)
            {
                smaxa=nums[i];
            }
        }

        if(maxa<2*smaxa)
        {
            return -1;
        }
        else
        {
            return maxa_index;
        }
    }
};