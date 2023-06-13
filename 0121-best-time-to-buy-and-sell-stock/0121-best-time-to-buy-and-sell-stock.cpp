class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_prices=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            int cost = prices[i] - min_prices;
            profit=max(profit,cost);
            min_prices=min(prices[i],min_prices);
        }
        return profit;
    }
};