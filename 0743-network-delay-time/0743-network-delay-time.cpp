class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        for(auto it: times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node])
            {
                int adjN = it.first;
                int edjW = it.second;
                if(dis + edjW < dist[adjN])
                {
                    dist[adjN] = dis + edjW;
                    pq.push({dis+edjW,adjN});
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
              return -1;
            else
              sum=max(sum,dist[i]);
        }
        return sum;
    }
};