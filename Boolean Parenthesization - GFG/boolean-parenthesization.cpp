//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1003;
private:
    int f(int i, int j, int isTrue, string S, vector<vector<vector<int>>> &dp)
    {
        if(i>j)
          return 0;
        if(i==j)
        {
            if(isTrue)
               return S[i]=='T';
            else
               return S[i]=='F';
        }
        
        if(dp[i][j][isTrue]!=-1)
           return dp[i][j][isTrue];
           
        int ways = 0;
        for(int ind=i+1;ind<=j-1;ind=ind+2)
        {
            int lT = f(i,ind-1,1,S,dp);
            int lF = f(i,ind-1,0,S,dp);
            int rT = f(ind+1,j,1,S,dp);
            int rF = f(ind+1,j,0,S,dp);
            
            if(S[ind]=='&')
            {
                if(isTrue)
                  ways = (ways + (lT*rT)%mod)%mod;
                else
                  ways = (ways + (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod)%mod;
            }
            else if(S[ind]=='|')
            {
                if(isTrue)
                   ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lT*rT)%mod)%mod;
                else
                   ways = (ways + (lF*rF)%mod)%mod;
            }
            else
            {
                if(isTrue)
                   ways = (ways + (lF*rT)%mod + (lT*rF)%mod)%mod;
                else
                   ways = (ways + (lF*rF)%mod + (lT*rT)%mod)%mod;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
public:
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int>(2,-1)));
        return f(0,N-1,1,S,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends