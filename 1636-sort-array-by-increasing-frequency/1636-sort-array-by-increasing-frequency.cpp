class Solution {
private:
    static bool comp(pair<int,int>&a, pair<int,int> &b)
    {
        if(a.second==b.second)
          return a.first>b.first;
        return a.second<b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;

        for(auto it: nums)
          mp[it]++;

        vector<pair<int,int>> v;
        for(auto i: mp)
          v.push_back(i);

        sort(v.begin(),v.end(),comp);
        vector<int>ans;
        for(auto ele: v)
        {
            while(ele.second--)
              ans.push_back(ele.first);
        }
        return ans;
    }
};