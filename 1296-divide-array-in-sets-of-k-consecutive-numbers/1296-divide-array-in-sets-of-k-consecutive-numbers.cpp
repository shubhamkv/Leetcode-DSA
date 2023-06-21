class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n%k!=0)
          return false;
        map<int,int> mp;
        sort(nums.begin(),nums.end());
        for(auto i: nums)
          mp[i]++;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==0)
              continue;
            for(int j=0;j<k;j++)
            {
                int curr = nums[i]+j;
                if(mp[curr]==0)
                  return false;
                mp[curr]--;
            }
        }
        return true;
    }
};