class Solution {
public:
    int number_of_bouquets(vector<int>& bloomDay, int day, int k)
    {
        int n=bloomDay.size();
        int count=0;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=day)
            {
                count++;
            }
            else if(bloomDay[i] > day)
            {
                count=0;
            }

            if(count == k)
            {
                ans++;
                count=0;
            }
        }

        return ans;
    }

    int find_high(vector<int>& bloomDay)
    {
        int maxa=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            maxa=max(maxa,bloomDay[i]);
        }

        return maxa;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=find_high(bloomDay);
        int ans=-1;
        while(low<=high)
        {
            int mid = ((high - low)/2)+low;
            int number = number_of_bouquets(bloomDay,mid,k);

            if(number>=m)
            {
                ans = mid;
                high = mid-1;
            }
            else if(number < m)
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};