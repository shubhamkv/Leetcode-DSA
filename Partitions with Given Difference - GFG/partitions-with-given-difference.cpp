//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    int mod = 1e9+7;
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
          
        return dp[ind][sum] = (pick + notPick)%mod;
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum=0;
        for(int i=0;i<n;i++)
           totalSum+=arr[i];
           
        if(totalSum-d<0 || (totalSum-d)%2) 
          return 0;
        int target = (totalSum - d)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
           
        return f(n-1,target,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends