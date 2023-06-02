class Solution {
private:
    // --------------Memoization DP Solution------------

    // int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp)
    // {
    //     if(j<0 || j>=matrix.size())
    //        return 1e9;
    //     if(i==0)
    //       return matrix[i][j];
        
    //     if(dp[i][j]!=-1)
    //       return dp[i][j];

    //     int s = matrix[i][j] + f(i-1,j,matrix,dp);
    //     int ld = matrix[i][j] + f(i-1,j-1,matrix,dp);
    //     int rd = matrix[i][j] + f(i-1,j+1,matrix,dp);

    //     return dp[i][j] = min(s,min(ld,rd));
    // }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int> (n,-1));
        // int mini = 1e9;

        // for(int j=0;j<n;j++)
        //   mini = min(mini,f(n-1,j,matrix,dp));

        // return mini;

        // ---------------Tabulation DP Solution---------------

        // vector<vector<int>> dp(n, vector<int>(n,0));
        // for(int j=0;j<n;j++)
        //   dp[0][j] = matrix[0][j];

        // for(int i=1;i<n;i++)
        // {
        //   for(int j=0;j<n;j++)
        //   {
        //       int s = matrix[i][j] + dp[i-1][j];
              
        //       int ld = matrix[i][j] ;
        //       if(j-1>=0)
        //         ld+= dp[i-1][j-1];
        //       else
        //         ld+= 1e9;

        //       int rd = matrix[i][j] ;
        //       if(j+1<n)
        //         rd+= dp[i-1][j+1];
        //       else
        //         rd+= 1e9;

        //       dp[i][j] = min(s,min(ld,rd));
        //   }
        // }

        // int mini = dp[n-1][0];
        // for(int j=1;j<n;j++)
        // {
        //   mini= min(mini , dp[n-1][j]);
        // }
        // return mini;

        // ---------------- Space Optimization--------------------

        vector<int> prev(n), curr(n);
        for(int j=0;j<n;j++)
          prev[j] = matrix[0][j];

        for(int i=1;i<n;i++)
        {
          for(int j=0;j<n;j++)
          {
              int s = matrix[i][j] + prev[j];
              
              int ld = matrix[i][j] ;
              if(j-1>=0)
                ld+= prev[j-1];
              else
                ld+= 1e9;

              int rd = matrix[i][j] ;
              if(j+1<n)
                rd+= prev[j+1];
              else
                rd+= 1e9;

              curr[j] = min(s,min(ld,rd));
          }
          prev = curr;
        }

        int mini = prev[0];
        for(int j=1;j<n;j++)
        {
          mini= min(mini , prev[j]);
        }
        return mini;
    }
};