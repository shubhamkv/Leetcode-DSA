class Solution {
    // --------------- Memoization DP Solution -----------------------------
// private:
//     int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
//     {
//         if(ind==nums.size())
//            return 0;

//         if(dp[ind][prev_ind+1]!=-1)
//            return dp[ind][prev_ind+1];

//         int notTake = f(ind+1,prev_ind,nums,dp);
//         int take=0;
//         if(prev_ind==-1 || nums[ind]>nums[prev_ind])
//            take = 1 +  f(ind+1,ind,nums,dp);
        
//         return dp[ind][prev_ind+1] = max(take, notTake);
//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return f(0,-1,nums,dp);

        // ------------------- Tabulation DP Solution ------------------

        // vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        //     {
        //         int notTake = dp[ind+1][prev_ind+1];
        //         int take=0;
        //         if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        //           take = 1 +  dp[ind+1][ind+1];
        
        //         dp[ind][prev_ind+1] = max(take, notTake);
        //     }
        // }
        // return dp[0][0];

        // ---------------- Space Optimization ---------------------------

        vector<int> ahead(n+1,0), curr(n+1,0);

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
            {
                int notTake = ahead[prev_ind+1];
                int take=0;
                if(prev_ind==-1 || nums[ind]>nums[prev_ind])
                  take = 1 +  ahead[ind+1];
        
                curr[prev_ind+1] = max(take, notTake);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};