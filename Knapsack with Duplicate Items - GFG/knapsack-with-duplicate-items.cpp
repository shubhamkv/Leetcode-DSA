//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    // --------------Memoization DP Solution---------------------------------
// private:
//     int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
//     {
//         if(ind==0)
//         {
//             return int(W/wt[0])*val[0];
//         }
        
//         if(dp[ind][W]!=-1)
//           return dp[ind][W];
        
//         int notTake = 0 + f(ind-1,W,wt,val,dp);
//         int take = INT_MIN;
//         if(wt[ind]<=W)
//           take = val[ind] + f(ind,W-wt[ind],wt,val,dp);
           
//         return dp[ind][W] = max(notTake,take);
//     }
 public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // vector<vector<int>> dp(N, vector<int> (W+1,-1));
        // return f(N-1,W,wt,val,dp);
        
        // -----------------------Tabulation DP Solution-------------------------
        
        // vector<vector<int>> dp(N, vector<int> (W+1,0));
        
        // for(int weight=0;weight<=W;weight++)
        // {
        //     dp[0][weight] = int(weight/wt[0]) * val[0];
        // }
        
        // for(int ind=1;ind<N;ind++)
        // {
        //     for(int weight=0;weight<=W;weight++)
        //     {
        //         int notTake = 0 + dp[ind-1][weight];
        //         int take = INT_MIN;
        //         if(wt[ind]<=weight)
        //         take = val[ind] + dp[ind][weight-wt[ind]];
           
        //         dp[ind][weight] = max(notTake,take);
        //     }
        // }
        
        // return dp[N-1][W];
        
        // --------------------------Space Optimization---------------------------
        
        vector<int> prev(W+1,0) , curr(W+1,0);
        
        for(int weight=0;weight<=W;weight++)
        {
            prev[weight] = int(weight/wt[0]) * val[0];
        }
        
        for(int ind=1;ind<N;ind++)
        {
            for(int weight=0;weight<=W;weight++)
            {
                int notTake = 0 + prev[weight];
                int take = INT_MIN;
                if(wt[ind]<=weight)
                take = val[ind] + curr[weight-wt[ind]];
           
                curr[weight] = max(notTake,take);
            }
            prev = curr;
        }
        
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends