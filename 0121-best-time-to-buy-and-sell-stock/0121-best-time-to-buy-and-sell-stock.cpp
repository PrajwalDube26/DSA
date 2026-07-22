class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>min_array;
        min_array.push_back(prices[0]);

        for(int i=1;i<prices.size();i++)
        {
            int mini=min(min_array[min_array.size()-1] , prices[i]);
            min_array.push_back(mini);
        }

        int max_Diff=INT_MIN;
        for(int i=1;i<prices.size();i++)
        {
            max_Diff=max(max_Diff , prices[i]-min_array[i-1]);
        }
        if(max_Diff<=0)
        {
            return 0;
        }
        return max_Diff;
    }
};