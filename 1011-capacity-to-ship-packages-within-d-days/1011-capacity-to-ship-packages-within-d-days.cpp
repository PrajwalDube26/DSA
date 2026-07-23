class Solution {
public:
    int required_day(vector<int>& weights, int& mid, int& n)
    {
        int a =mid;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(weights[i]<=a)
            {
                a-=weights[i];
            }
            else if(weights[i]>a)
            {
                ans++;
                a=mid;
                a-=weights[i];
            }
        }

        if(a<mid)
        {
            ans++;
        }

        return ans;
    }

    pair<int,int> high_sum(vector<int>& weights, int& n)
    {
        int maxa=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
            maxa = max(maxa,weights[i]);
        }
        return {maxa,sum};
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        pair<int,int> a=high_sum(weights,n);

        int low = a.first;
        int high = a.second;
        int ans=-1;

        while(low <= high)
        {
            int mid = ((high-low)/2) + low;
            int rday = required_day(weights,mid,n);
                
            if(rday <= days)
            {
                ans = mid;
                high = mid-1;
            }
            else if(rday > days)
            {
                low = mid+1;
            }
        }

        return ans;
    }
};