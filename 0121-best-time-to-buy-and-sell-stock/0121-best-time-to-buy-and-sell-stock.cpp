class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxa_profit=0;
        int mini=0,maxa=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<prices[mini])
            {
                mini=i;
                maxa=i;
            }
            else if(prices[i] > prices[maxa])
            {
                maxa=i;
            }
            
            maxa_profit=max(maxa_profit,prices[maxa]-prices[mini]);
        }

        return maxa_profit;
    }
};