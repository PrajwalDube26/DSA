class Solution {
public:
    int timereq(int mid,vector<int>& piles)
    {
        int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            int a =piles[i]/mid;
            int b = piles[i]%mid;
            if(b>0)
            {
                ans+=a+1;
            }
            else if(b==0)
            {
                ans+=a;
            }
        }

        return ans;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MAX;
        int ans;
        while(low<=high)
        {
            int mid = ((high-low)/2) +low;
            int time = timereq(mid,piles);
            if(time <= h)
            {
                ans =mid;
                high = mid-1;
            }
            else if(time>h)
            {
                low=mid+1;
            }
        }

        return ans;
    }
};