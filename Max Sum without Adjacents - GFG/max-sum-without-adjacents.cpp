//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // int f(int ind, int arr[], vector<int> &dp)
    // {
    //     if(ind==0)
    //       return arr[ind];
    //     if(ind<0)
    //       return 0;
        
    //     if(dp[ind]!=-1)
    //       return dp[ind];
          
    //     int pick = arr[ind] + f(ind-2,arr,dp);
    //     int notPick = 0 + f(ind-1,arr,dp);
        
    //     return dp[ind]=max(pick,notPick);
    // }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	   // vector<int> dp(n,-1);
	   // return f(n-1,arr,dp);
	   //--------------------------------------------------------------------------------
	   
	   // Tabulation in DP
	   
	   //vector<int> dp(n,0);
	   //dp[0]=arr[0];
	   //for(int i=1;i<n;i++)
	   //{
	   //    int pick = arr[i];
	   //    if(i>1)
	   //       pick+=dp[i-2];
	   //    int notPick = 0 + dp[i-1];
	   //    dp[i] = max(pick,notPick);
	   //}
	   //return dp[n-1];
	   
	   //-----------------------------Space Optimization----------------------------------
	   
	   vector<int> dp(n,0);
	   int prev=arr[0];
	   int prev2=0;
	   for(int i=1;i<n;i++)
	   {
	       int pick = arr[i];
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends