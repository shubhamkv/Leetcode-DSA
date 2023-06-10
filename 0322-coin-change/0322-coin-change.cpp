class Solution {

    // ----------------- Memoization DP Solution -------------------------
// private:
//     int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
//     {
//         if(ind==0)
//         {
//             if(amount%coins[0]==0)
//               return amount/coins[0];
//             return 1e9;
//         }
//         if(dp[ind][amount]!=-1)
//            return dp[ind][amount];
        
//         int notTake = 0 + f(ind-1,amount,coins,dp);
//         int take = 1e9;
//         if(coins[ind]<=amount)
//            take = 1 + f(ind,amount-coins[ind],coins,dp);

//         return dp[ind][amount] = min(notTake,take);
//     }
public:
    int coinChange(vector<int>& coins, int amount) {
    
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        // int ans = f(n-1,amount,coins,dp);

        // ------------------ Tabulation DP Solution ---------------------

        // vector<vector<int>> dp(n, vector<int>(amount+1,0));
        
        // for(int target=0;target<=amount;target++)
        // {
        //     if(target%coins[0]==0)
        //        dp[0][target] = target / coins[0];
        //     else
        //        dp[0][target] = 1e9;
        // }

        // for(int ind =1; ind<n;ind++)
        // {
        //     for(int target=0;target<=amount;target++)
        //     {
        //         int notTake = 0 + dp[ind-1][target];
        //         int take = 1e9;
        //         if(coins[ind]<=target)
        //             take = 1 + dp[ind][target-coins[ind]];

        //         dp[ind][target] = min(notTake,take);
        //     }
        // }
        
        // int ans = dp[n-1][amount];

        // ---------------------------- Space Optimization ------------------

        vector<int> prev(amount+1) , curr(amount+1);
        
        for(int target=0;target<=amount;target++)
        {
            if(target%coins[0]==0)
               prev[target] = target / coins[0];
            else
               prev[target] = 1e9;
        }

        for(int ind =1; ind<n;ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int notTake = 0 + prev[target];
                int take = 1e9;
                if(coins[ind]<=target)
                    take = 1 + curr[target-coins[ind]];

                curr[target] = min(notTake,take);
            }
            prev = curr;
        }
        
        int ans = prev[amount];

        if(ans>=1e9)
          return -1;
        return ans;
    }
};