class Solution {
public:

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int>next(arr.size(),arr.size());
        vector<int>prev(arr.size(),-1);

        stack<pair<int,int>>s1;
        s1.push({arr[0],0});

        for(int i=1;i<arr.size();i++)
        {
            while(!s1.empty() && s1.top().first >=arr[i])
            {
                next[s1.top().second] = i;
                s1.pop();
            }
            s1.push({arr[i],i});
        }

        while(!s1.empty())
        {
            s1.pop();
        }

        int n = arr.size();

        s1.push({arr[n-1],n-1});

        for(int i=n-2;i>=0;i--)
        {
            while(!s1.empty() && s1.top().first >arr[i])
            {
                prev[s1.top().second] = i;
                s1.pop();
            }
            s1.push({arr[i],i});
        }

        long long ans = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++)
        {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = ans + (arr[i] * left * right);
        }

        return ans;
    }





    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int>next(arr.size(),arr.size());
        vector<int>prev(arr.size(),-1);

        stack<pair<int,int>>s1;
        s1.push({arr[0],0});

        for(int i=1;i<arr.size();i++)
        {
            while(!s1.empty() && s1.top().first <=arr[i])
            {
                next[s1.top().second] = i;
                s1.pop();
            }
            s1.push({arr[i],i});
        }

        while(!s1.empty())
        {
            s1.pop();
        }

        int n = arr.size();

        s1.push({arr[n-1],n-1});

        for(int i=n-2;i>=0;i--)
        {
            while(!s1.empty() && s1.top().first < arr[i])
            {
                prev[s1.top().second] = i;
                s1.pop();
            }
            s1.push({arr[i],i});
        }

        long long ans = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++)
        {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = ans + (arr[i] * left * right) ;
        }

        return ans;
    }



    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};