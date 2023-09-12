class Solution {
public:

    static bool comp(pair<char,int>&a,pair<char,int>&b)
    {
        return a.second>b.second;
    }

    int minDeletions(string s) {
        
        unordered_map<char,int> mp;
        int n= s.size();
        unordered_set<int> st;
        int cnt=0;
        
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        
        for(auto it:mp)
        {
            int freq = it.second;
            while(freq>0 && st.find(freq)!=st.end())
            {
                freq--;
                cnt++;
            }
            st.insert(freq);
        }
        return cnt;
    }
};