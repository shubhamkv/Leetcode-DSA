class Solution {
  // -------------- Memoization DP Solution --------------------------------
// private:
//     int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
//     {
//         if(ind>=prices.size())
//           return 0;
        
//         if(dp[ind][buy]!=-1)
//           return dp[ind][buy];
    
//         int profit=0;
//         if(buy)
//            profit = max(-prices[ind] + f(ind+1,0,prices,dp), 0 + f(ind+1,1,prices,dp));
//         else
//            profit = max(prices[ind] + f(ind+2,1,prices,dp), 0 + f(ind+1,0,prices,dp));

//         return dp[ind][buy] = profit;
//     }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // return f(0,1,prices,dp);

        // --------------- Tabulation DP Solution ----------------

        vector<vector<int>> dp(n+2, vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            //buy
              dp[ind][1]= max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            //sell
              dp[ind][0]= max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);  
        }
        return dp[0][1];

        // ----------------- Space Optimization -----------------------------

        vector<int> ahead2(2,0);
        vector<int> ahead1(2,0);
        vector<int> curr(2,0);

        for(int ind=n-1;ind>=0;ind--)
        {
            //buy
              curr[1]= max(-prices[ind] + ahead1[0], 0 + ahead1[1]);
            //sell
              curr[0]= max(prices[ind] + ahead2[1], 0 + ahead1[0]);  

            ahead2 = ahead1;
            ahead1 = curr;
        }
        return curr[1];
    }
};