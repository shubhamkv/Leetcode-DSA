class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

       vector<pair<long,long>> adj[n];
       for(auto it: roads)
       {
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       } 

       priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
       vector<long> dist(n,1e15), ways(n,0);
       dist[0]=0;
       ways[0]=1;
       pq.push({0,0});
       int mod = 1e9+7;
        
       while(!pq.empty())
       {
           long time = pq.top().first;
           long node = pq.top().second;
           pq.pop();

           for(auto it: adj[node])
           {
               long adjN = it.first;
               long edgW = it.second;
              
               if(time + edgW < dist[adjN])
               {
                   dist[adjN]=time + edgW;
                   pq.push({dist[adjN],adjN});
                   ways[adjN]=ways[node];
               }
               else if(time + edgW == dist[adjN])
                   ways[adjN]= (ways[adjN]+ways[node]) % mod;
           }
       }
       return ways[n-1] % mod;
    }
};