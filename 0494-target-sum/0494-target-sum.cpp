class Solution {
private:
    int f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(sum==0 && arr[0]==0)
                return 2;
            if(sum==0 || sum==arr[0])
                return 1;
            return 0;
        }
        
        if(dp[ind][sum]!=-1)
          return dp[ind][sum];
        
        int notPick = f(ind-1,sum,arr,dp);
        int pick = 0;
        if(sum>=arr[ind])
          pick = f(ind-1,sum-arr[ind],arr,dp);
          
        return dp[ind][sum] = (pick + notPick);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int totalSum=0;
        
        for(int i=0;i<n;i++)
           totalSum+=nums[i];
           
        if(totalSum-target<0 || (totalSum-target)%2) 
           return 0;
        
        int sum = (totalSum - target)/2;
        
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return f(n-1,sum,nums,dp);
    }
};