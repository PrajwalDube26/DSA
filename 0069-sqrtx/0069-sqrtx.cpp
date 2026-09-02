class Solution {
public:
    int check(int mid,int x)
    {
        long long cal_sqr =1LL * mid * mid;

        if(cal_sqr <= x)
        {
            return mid;
        }
        else if(cal_sqr > x)
        {
            return -1;
        }

        return -1;
    }

    int mySqrt(int x)
    {
        int low=0,high=x,ans;

        while(low<=high)
        {
            int mid = ((high - low)/2) +low;
            int value = check(mid,x);

            if(value != -1)
            {
                ans = value;
                low=mid+1;
            }
            else if(value == -1)
            {
                high = mid-1;
            }
        }
        return ans;
    }
};