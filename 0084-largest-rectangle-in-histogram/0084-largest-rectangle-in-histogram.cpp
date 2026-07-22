class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n,n);
        vector<int>prev(n,-1);

        stack<pair<int,int>>s1;
        s1.push({heights[0],0});

        for(int i=1;i<n;i++)
        {
            while(!s1.empty() && s1.top().first > heights[i])
            {
                next[s1.top().second] = i;
                s1.pop();
            }
            s1.push({heights[i],i});
        }

        while (!s1.empty())
        {
            s1.pop();
        }

        s1.push({heights[n-1],n-1});

        for(int i=n-2;i>=0;i--)
        {
            while(!s1.empty() && s1.top().first > heights[i])
            {
                prev[s1.top().second] = i;
                s1.pop();
            }
            s1.push({heights[i],i});
        }


        int maxa = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int width = (next[i]-1) - (prev[i]+1) + 1; 
            int sq = width*heights[i];

            maxa = max(maxa,sq);
        }

        return maxa;
    }
};