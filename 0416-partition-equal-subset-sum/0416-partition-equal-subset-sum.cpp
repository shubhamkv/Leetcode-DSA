class Solution {
  // ------------------ Tabulation DP Solution ----------------------------
private: 
    bool isSubsetSum(vector<int> &nums, int target, int n){
        
        vector<vector<bool>> dp(n, vector<bool>(target+1,0));
        for(int i=0;i<n;i++)
          dp[i][0] = true;
        if(nums[0]<=target)
           dp[0][nums[0]] = true;
        
        for(int i=1;i<n;i++)
        {
            for(int tar=1;tar<=target;tar++)
            {
                bool notTake = dp[i-1][tar];
                bool take = false;
                if(tar>=nums[i])
                  take = dp[i-1][tar-nums[i]];
          
                dp[i][tar] = (take || notTake) ;
            }
        }
        return dp[n-1][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
          return false;
        int totalSum=0;
        for(int i=0;i<n;i++)
           totalSum+= nums[i];
        
        if(totalSum%2)
          return false;
        
        int target = totalSum / 2;
        return isSubsetSum(nums,target,n);
    }
};