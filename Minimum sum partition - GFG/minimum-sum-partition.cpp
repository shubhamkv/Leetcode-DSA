//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	            
        int totalSum = 0;
        for(int i=0;i<n;i++)
          totalSum+=nums[i];
        
        vector<vector<bool>> dp(n, vector<bool> (totalSum+1,false));
        for(int i=0;i<n;i++)
          dp[i][0] = true;

        if(nums[0]<=totalSum)
          dp[0][nums[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=totalSum;target++)
            {
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target>=nums[i])
                   take = dp[i-1][target - nums[i]];
                dp[i][target] = take || notTake;
            }
        }

        int mini = 1e9;
        for(int i=0;i<=totalSum/2;i++)
        {
            if(dp[n-1][i]==true)
            {
              mini = min(mini,abs((totalSum-i)-i));
            }
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends