class Solution {
    static bool comp(string &s1, string &s2){
         
        return s1.size()<s2.size();
    }

private:
    bool compare(string &s1, string &s2)
    {
        if(s1.size()!=s2.size()+1)
          return false;

        int i=0,j=0;
        while(i<s1.size())
        {
            if(s1[i]==s2[j] && j<s2.size())
            {
                i++;
                j++;
            }
            else
               i++;
        }

        if(i==s1.size() && j==s2.size())
           return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        
        int n= words.size();
        int maxi =1;
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),comp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(words[i],words[j]) && 1 + dp[j]>dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi  = max(maxi,dp[i]);
        }
        return maxi;
    }
};