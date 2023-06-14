class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,1) , hash(n,1);

        int ans=-1;
        int lastind = 0;
        sort(nums.begin(),nums.end());

        for(int ind=0;ind<n;ind++)
        {
            hash[ind]=ind;
            for(int prev_ind=0;prev_ind<ind;prev_ind++)
            {
                if(nums[ind]%nums[prev_ind]==0 && 1+dp[prev_ind]>dp[ind])
                {
                    dp[ind] = 1 + dp[prev_ind];
                    hash[ind] = prev_ind;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(ans<dp[i])
            {
                lastind = i;
                ans = dp[i];
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastind]);
        
        while(hash[lastind]!=lastind)
        {
            lastind = hash[lastind];
            temp.push_back(nums[lastind]);
        }

        reverse(temp.begin(),temp.end());
        return temp;
    }
};