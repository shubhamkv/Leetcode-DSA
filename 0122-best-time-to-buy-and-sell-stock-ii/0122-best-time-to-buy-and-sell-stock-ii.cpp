class Solution {
  // ---------------- Memoization DP solution ------------------------------
// private:
//     int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
//     {
//         if(ind==prices.size())
//           return 0;
        
//         if(dp[ind][buy]!=-1)
//           return dp[ind][buy];
    
//         int profit=0;
//         if(buy)
//            profit = max(-prices[ind] + f(ind+1,0,prices,dp), 0 + f(ind+1,1,prices,dp));
//         else
//            profit = max(prices[ind] + f(ind+1,1,prices,dp), 0 + f(ind+1,0,prices,dp));

//         return dp[ind][buy] = profit;
//     }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        // vector<vector<int>>dp(n+1, vector<int>(2,-1));
        // return f(0,1,prices,dp);

        // ---------------- Tabulation DP Solution ----------------------------

        // vector<vector<int>>dp(n+1, vector<int>(2,0));

        // dp[n][0] = dp[n][1] = 0;

        // int profit=0;

        // for(int ind=n-1;ind>=0;ind--)
        // {
        //    for(int buy=0;buy<=1;buy++)
        //    {
        //      if(buy)
        //         profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        //      else
        //         profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);

        //      dp[ind][buy] = profit;
        //    }
        // }
        // return dp[0][1];

        // ------------------ 2D Space Optimization -------------------------

        // vector<int> ahead(2,0), curr(2,0);

        // ahead[0] = ahead[1] = 0;

        // int profit=0;

        // for(int ind=n-1;ind>=0;ind--)
        // {
        //    for(int buy=0;buy<=1;buy++)
        //    {
        //      if(buy)
        //         profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
        //      else
        //         profit = max(prices[ind] + ahead[1], 0 + ahead[0]);

        //      curr[buy] = profit;
        //    }
        //    ahead = curr;
        // }
        // return ahead[1];

        // ------------------- O(1) Space Optimization -------------------------

        int aheadnotBuy, aheadBuy, currnotBuy, currBuy;

        aheadnotBuy = aheadBuy = 0;

        for(int ind=n-1;ind>=0;ind--)
        {    
            currBuy = max(-prices[ind] + aheadnotBuy, 0 + aheadBuy);
            
            currnotBuy = max(prices[ind] + aheadBuy, 0 + aheadnotBuy);
           
            aheadnotBuy = currnotBuy;
            aheadBuy = currBuy;
        }
        return aheadBuy;
    }
};