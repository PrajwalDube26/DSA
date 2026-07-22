class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0,sum=0,maxa=INT_MIN;

        while(j<nums.size())
        {
            sum=sum+nums[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxa=max(maxa,sum);
                sum=sum-nums[i];
                i++;
                j++;
            }
        }

        double ans=(double)maxa/k;

        return ans;
    }
};