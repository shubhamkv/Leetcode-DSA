//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    
// ---------------Memoization DP Solution----------------------------------------

// private:
//     bool f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
//     {
//         if(sum==0)
//           return true;
//         if(ind==0)
//           return arr[ind]==sum;
        
//         if(dp[ind][sum]!=-1)
//           return dp[ind][sum];
           
//         bool notTake = f(ind-1,sum,arr,dp);
//         bool take = false;
//         if(sum>=arr[ind])
//           take = f(ind-1,sum-arr[ind],arr,dp);
          
//         return dp[ind][sum] = (take || notTake) ;
//     }

public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        // return f(n-1,sum,arr,dp);
        
        // --------------------Tabulation DP Solution---------------------
        
        // vector<vector<bool>> dp(n, vector<bool>(sum+1,0));
        // for(int i=0;i<n;i++)
        //   dp[i][0] = true;
        // dp[0][arr[0]] = true;
        
        // for(int i=1;i<n;i++)
        // {
        //     for(int target=1;target<=sum;target++)
        //     {
        //         bool notTake = dp[i-1][target];
        //         bool take = false;
        //         if(target>=arr[i])
        //           take = dp[i-1][target-arr[i]];
          
        //         dp[i][target] = (take || notTake) ;
        //     }
        // }
        // return dp[n-1][sum];
        
        // ------------------Space Optimization----------------------------------------
        
        vector<bool> prev(sum+1,0), curr(sum+1,0);
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if(target>=arr[i])
                   take = prev[target-arr[i]];
          
                curr[target] = (take || notTake) ;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends