class Solution {
private:
    // --------------- Tabulation DP Solution -------------------------

    // int lps(string s)
    // {
    //     string t = s;
    //     reverse(t.begin(),t.end());

    //     int n = s.size();
    //     int m = t.size();

    //     vector<vector<int>> dp(n+1, vector<int> (m+1,0));

    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             if(s[i-1]==t[j-1])
    //               dp[i][j] = 1 + dp[i-1][j-1];
    //             else
    //               dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     return dp[n][m];
    //}

    // ------------------ Space Optimization ----------------------

    int lps(string s)
    {
        string t = s;
        reverse(t.begin(),t.end());

        int n = s.size();
        int m = t.size();

        vector<int> prev(m+1,0), curr(m+1,0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                  curr[j] = 1 + prev[j-1];
                else
                  curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int minInsertions(string s) {
        
        return s.size() - lps(s);
    }
};