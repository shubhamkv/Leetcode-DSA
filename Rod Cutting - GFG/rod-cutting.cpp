//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    // ------------------ Memoization DP Solution---------------------------
//   private:
//   int f(int ind, int N, int price[], vector<vector<int>> &dp)
//   {
//       if(ind==0)
//         return N*price[0];
      
//       if(dp[ind][N]!=-1)
//         return dp[ind][N];
        
//       int notTake = 0 + f(ind-1,N,price,dp);
//       int take = INT_MIN;
//       int rodlength = ind+1;
//       if(rodlength<=N)
//         take = price[ind] + f(ind,N-rodlength,price,dp);
        
//       return dp[ind][N] = max(take,notTake);
//   }
  public:
    int cutRod(int price[], int n) {
        //code here
        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return f(n-1,n,price,dp);
        
        // ------------------- Tabulation DP Solution-----------------
        
        // vector<vector<int>> dp(n, vector<int>(n+1,0));
        
        // for(int N=0;N<=n;N++)
        //   dp[0][N] = N*price[0];
          
        // for(int ind=1;ind<n;ind++)
        // {
        //     for(int N=0;N<=n;N++)
        //     {
        //         int notTake = 0 + dp[ind-1][N];
        //         int take = INT_MIN;
        //         int rodlength = ind+1;
        //         if(rodlength<=N)
        //           take = price[ind] + dp[ind][N-rodlength];
        
        //         dp[ind][N] = max(take,notTake);
        //     }
        // }
        //  return dp[n-1][n];
        
        // ---------------- Space Optimization-------------------------------
        
        vector<int> prev(n+1,0), curr(n+1,0);
        
        for(int N=0;N<=n;N++)
          prev[N] = N*price[0];
          
        for(int ind=1;ind<n;ind++)
        {
            for(int N=0;N<=n;N++)
            {
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodlength = ind+1;
                if(rodlength<=N)
                  take = price[ind] + curr[N-rodlength];
        
                curr[N] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends