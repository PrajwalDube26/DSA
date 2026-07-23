class Solution {
public:
    int sum_after_devide(vector<int>& nums,int n,int mid)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=ceil((double)nums[i]/mid);
        }

        return sum;
    }

    int find_high(vector<int>& nums,int n)
    {
        int maxa=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxa=max(maxa,nums[i]);
        }
        return maxa;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1,high=find_high(nums,n);
        int ans=-1;
        while(low<=high)
        {
            int mid=((high-low)/2)+low;
            int sum =sum_after_devide(nums,n,mid);

            if(sum <= threshold)
            {
                ans =mid;
                high = mid-1;
            }
            else if(sum > threshold)
            {
                low=mid+1;
            }
        }

        return ans;
    }
};