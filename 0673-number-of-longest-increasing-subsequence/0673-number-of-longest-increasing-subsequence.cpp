class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
	    int maxi = 1;
	    
	    vector<int> dp(n,1), cnt(n,1);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(nums[i]>nums[j] && 1+dp[j]>dp[i])
	            {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];  // inherit   
                } 
                else if(nums[i]>nums[j] && dp[j]+1==dp[i])
                   cnt[i]+=cnt[j]; // increasing the count
	        }
            maxi = max(maxi,dp[i]);
	    }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(maxi==dp[i])
              ans+=cnt[i];
        }
        return ans;
    }
};