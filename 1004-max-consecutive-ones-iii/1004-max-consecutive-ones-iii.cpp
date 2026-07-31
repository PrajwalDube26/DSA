class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right=0,left=0;
        int n = nums.size();
        int count0=0,count1=0,maxa=0;

        for(right=0;right<n;right++)
        {
            if(nums[right]==0)
            {
                if(count0<k)
                {
                    // for right 0
                    count0++;
                }
                else if(count0==k)
                {
                    while(count0==k)
                    {
                        if(nums[left]==0)
                        {
                            count0--;
                        }
                        left++;
                    }

                    // for right 0
                    count0++;
                }

                maxa=max(maxa,right-left+1);

            }
            else if(nums[right]==1)
            {
                maxa=max(maxa,right-left+1);
            }
        }

        return maxa;
    }
};