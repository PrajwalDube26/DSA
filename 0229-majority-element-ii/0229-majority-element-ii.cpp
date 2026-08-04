class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int needed = (n/3)+1;
        int cnt1=0,ma1=INT_MIN;
        int cnt2=0,ma2=INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && ma2!=nums[i])
            {
                cnt1=1;
                ma1=nums[i];
            }
            else if(cnt2==0 && ma1!=nums[i])
            {
                cnt2=1;
                ma2=nums[i];
            }
            else if(ma1 == nums[i])
            {
                cnt1++;
            }
            else if(ma2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0,cnt2=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==ma1)
            {
                cnt1++;
            }

            if(nums[i]==ma2)
            {
                cnt2++;
            }
        }

        if(cnt1>=needed)
        {
            ans.push_back(ma1);
        }

        if(cnt2>=needed)
        {
            ans.push_back(ma2);
        }

        return ans;
    }
};