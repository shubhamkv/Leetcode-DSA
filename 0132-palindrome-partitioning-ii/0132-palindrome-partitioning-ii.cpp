class Solution {
private:
    bool isPalindrome(int i, int j, string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
              return false;
            i++;
            j--;
        }
        return true;
    }
    // --------------- Memoizaion DP Solution -----------------------

// private:
//     int f(int i, string &s, vector<int> &dp)
//     {
//         if(i==s.size())
//           return 0;
        
//         if(dp[i]!=-1)
//           return dp[i];
        
//         int mini = INT_MAX;
//         for(int j=i;j<s.size();j++)
//         {
//             if(isPalindrome(i,j,s))
//             {
//                 int cost = 1 + f(j+1,s,dp);
//                 mini = min(mini,cost);
//             }
//         }
//         return dp[i] = mini;
//     }
public:
    int minCut(string s) {
          
        int n = s.size();

        // vector<int> dp(n,-1);
        // return f(0,s,dp)-1;

        // ---------------- Tabulation DP Solution --------------------

        vector<int> dp(n+1,0);
        dp[n] = 0;

        for(int i=n-1;i>=0;i--)
        {
            int mini = INT_MAX;
            for(int j=i;j<n;j++)
            {
               if(isPalindrome(i,j,s))
               {
                   int cost = 1 + dp[j+1];
                   mini = min(mini,cost);
               }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};