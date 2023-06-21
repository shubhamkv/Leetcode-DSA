class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // top k frequent means --- top k elements whose frequency is highest among others
        // e.g 1 -- k=2 so, freq of 1 and 2 is higher than 3 so return it...

        int n = nums.size();
        
        // -------- Max Heap -----------------

        // if(k==n)       // if it is the case then it is clearly every element occurs only one
        //   return nums;  // so we simply return nums

        // map<int,int> mp;
        // vector<int> ans;
        // priority_queue<pair<int,int>> pq;
        // for(int i=0;i<n;i++)
        // {
        //     mp[nums[i]]++;
        // }
        // for(auto i: mp)
        // {
        //     pq.push({i.second,i.first});
        // }

        // while(k--)
        // {
        //    ans.push_back(pq.top().second);
        //    pq.pop();
        // }
        // return ans;

        // ---------- Min Heap : as we have to find the top k elements --------------

        typedef pair<int,int> pi;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        unordered_map<int,int> mp;
        vector<int> ans;

        for(auto it:nums)
          mp[it]++;

        for(auto i:mp)
        {
            pq.push({i.second,i.first});
            if(pq.size()>k)
              pq.pop();
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};