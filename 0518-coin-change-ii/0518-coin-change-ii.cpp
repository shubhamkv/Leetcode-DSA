class Solution {
    //    ----------------- Memoization DP Solution -------------------------
// private:
//     int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
//     {
//         if(ind==0)
//         {
//             return (amount % coins[0]==0);
//         }
//         if(dp[ind][amount]!=-1)
//            return dp[ind][amount];
        
//         int notTake = f(ind-1,amount,coins,dp);
//         int take = 0;
//         if(coins[ind]<=amount)
//            take = f(ind,amount-coins[ind],coins,dp);

//         return dp[ind][amount] = notTake + take ;
//     }
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        // vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        // return f(n-1,amount,coins,dp);

        // ---------------- Tabulation DP Solution -----------------

        // vector<vector<int>> dp(n, vector<int>(amount+1,0));
        // for(int target=0;target<=amount;target++)
        // {
        //     dp[0][target] = (target % coins[0]==0);
        // }

        // for(int ind =1;ind<n;ind++)
        // {
        //     for(int target=0;target<=amount;target++)
        //     {
        //         int notTake = dp[ind-1][target];
        //         int take = 0;
        //         if(coins[ind]<=target)
        //             take = dp[ind][target-coins[ind]];

        //         dp[ind][target] = notTake + take ;
        //     }
        // }
        // return dp[n-1][amount];

        // ---------------------------Space Optimization -----------------------------

        vector<int> prev(amount+1,0) , curr(amount+1,0);

        for(int target=0;target<=amount;target++)
        {
            prev[target] = (target % coins[0]==0);
        }

        for(int ind =1;ind<n;ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notTake = prev[target];
                int take = 0;
                if(coins[ind]<=target)
                    take = curr[target-coins[ind]];

                curr[target] = notTake + take ;
            }
            prev = curr;
        }
        return prev[amount];
    }
};