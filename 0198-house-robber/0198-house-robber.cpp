class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        // --------------Tabulation DP--------------------

        // dp[0]=nums[0];
        // for(int i=1;i<n;i++)
        // {
        //     int pick = nums[i];
        //     if(i>1)
        //       pick+=dp[i-2];
        //     int notPick = 0 + dp[i-1];
        //     dp[i] = max(pick,notPick);
        // }
        // return dp[n-1];

        // -----------------Space Optimization------------------------
        
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1)
              pick+=prev2;
            int notPick = 0 + prev;
            int curr = max(pick,notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};