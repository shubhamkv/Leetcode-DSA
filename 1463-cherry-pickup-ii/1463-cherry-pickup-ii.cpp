class Solution {
    
// ------------------Memoization DP Solution-------------------------

// private:
//     int f(int i, int j1, int j2,int n, int m, vector<vector<int>>& grid, 
//     vector<vector<vector<int>>> &dp)
//     {
//         if(j1<0 || j1>=m || j2<0 || j2>m)
//            return -1e9;
//         if(i==n-1)
//         {
//             if(j1==j2)
//                return grid[i][j1];
//             else
//                return grid[i][j1]+grid[i][j2];
//         }

//         if(dp[i][j1][j2]!=-1)
//            return dp[i][j1][j2];
        
//         long long maxi = -1e9;
//         for(int dj1=-1;dj1<=1;dj1++)
//         {
//             for(int dj2=-1;dj2<=1;dj2++)
//             {
//                 long long value=0;
//                 if(j1==j2)
//                    value = grid[i][j2];
//                 else
//                    value = grid[i][j1] + grid[i][j2];
//                 value+= f(i+1, j1+dj1, j2+dj2, n,m, grid, dp);
//                 maxi = max(maxi,value);
//             }
//         }
//         return dp[i][j1][j2] = maxi;
//     }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m,-1)));
        // return f(0,0,m-1,n,m,grid,dp);

        // ------------------Tabulation DP Solution---------------------

        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m,-1)));
        // for(int j1=0;j1<m;j1++)
        // {
        //     for(int j2=0;j2<m;j2++)
        //     {
        //         if(j1==j2)
        //           dp[n-1][j1][j2] = grid[n-1][j1];
        //         else
        //           dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        //     }
        // }
        
        // for(int i=n-2;i>=0;i--)
        // {
        //     for(int j1=0;j1<m;j1++)
        //     {
        //         for(int j2=0;j2<m;j2++)
        //         {
        //             long long maxi = -1e9;
        //             for(int dj1=-1;dj1<=1;dj1++)
        //             {
        //                for(int dj2=-1;dj2<=1;dj2++)
        //                {
        //                   long long value=0;
        //                   if(j1==j2)
        //                     value = grid[i][j2];
        //                   else
        //                     value = grid[i][j1] + grid[i][j2];
        //                   if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
        //                      value+= dp[i+1][j1+dj1][j2+dj2] ;
        //                   else
        //                      value+= -1e9;
        //                   maxi = max(maxi,value);
        //                }
        //             }
        //             dp[i][j1][j2] = maxi;
        //         }
        //     }
        // }
        // return dp[0][0][m-1];

        // ----------------------Space Optimization------------------

        vector<vector<int>> front(m, vector<int>(m,0));
        vector<vector<int>> curr(m, vector<int>(m,0));
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                  front[j1][j2] = grid[n-1][j1];
                else
                  front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    long long maxi = -1e9;
                    for(int dj1=-1;dj1<=1;dj1++)
                    {
                       for(int dj2=-1;dj2<=1;dj2++)
                       {
                          long long value=0;
                          if(j1==j2)
                            value = grid[i][j2];
                          else
                            value = grid[i][j1] + grid[i][j2];
                           
                          if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                             value+= front[j1+dj1][j2+dj2] ;
                          else
                             value+= -1e9;
                          maxi = max(maxi,value);
                       }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m-1];
    }
};