class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            int key = (points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({key,{points[i][0],points[i][1]}});
            if(pq.size()>k)
              pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};