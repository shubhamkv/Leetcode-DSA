class Solution {
    // --------------- Memoization DP Solution ---------------------
// private: 
//     int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
//     {
//         if(cap==0 || ind==prices.size())
//           return 0;
        
//         if(dp[ind][buy][cap]!=-1)
//            return dp[ind][buy][cap];
           
//         if(buy)
//           return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1,0,cap,prices,dp),
//                                           0 + f(ind+1,1,cap,prices,dp));
        
//         return dp[ind][buy][cap] = max(prices[ind] + f(ind+1,1,cap-1,prices,dp),
//                                        0 + f(ind+1,0,cap,prices,dp));
//     }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3,-1)));
        // return f(0,1,2,prices,dp);

        // ---------------- Tabulation DP Solution ---------------------------

        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3,0)));

        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         for(int cap=1;cap<=2;cap++)
        //         {
        //             if(buy)
        //               dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],
        //                                   0 + dp[ind+1][1][cap]);
        //             else
        //               dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1],
        //                                0 + dp[ind+1][0][cap]);
        //         }
        //     }
        // }
        // return dp[0][1][2];

        // ------------------ Space Optimization ----------------------

        vector<vector<int>> ahead(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy)
                      curr[buy][cap] = max(-prices[ind] + ahead[0][cap],
                                          0 + ahead[1][cap]);
                    else
                      curr[buy][cap] = max(prices[ind] + ahead[1][cap-1],
                                       0 + ahead[0][cap]);
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};