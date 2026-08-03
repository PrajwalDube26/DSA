class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        long long sn=1LL * (n*(n+1))/2;  //+ missing_number
        long long s2n = 1LL *(((1LL *n*(n+1))/2)*(1LL *(2*n)+1))/3;
        long long sa=0,s2a=0;      //+ reapeated_number
        vector<int>ans(2);

        for(int i=0;i<n;i++)
        {
            sa +=nums[i];
            s2a +=1LL * nums[i]*nums[i];
        }

        int val1 = sn-sa;
        int val2 = (s2n - s2a)/(sn - sa);

        int missing_number = (val1 + val2)/2;
        int reapeated_number = (val2 - val1)/2;

        ans[0]=reapeated_number;
        ans[1]=missing_number;

        return ans;
    }
};