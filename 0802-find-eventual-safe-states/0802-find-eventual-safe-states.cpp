class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> graphRev(n);
        vector<int> ind(n,0);

        // reverse the graph and calculate indegree which is outdegree of original graph
        for(int i=0;i<n;i++)
        {
            // i->it
            // it->i
            for(auto it: graph[i])
            {
                graphRev[it].push_back(i);
                ind[i]++;
            }   
        }
        
        // bfs algo to detect cycle or topo sort algo
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
              q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
           int node = q.front();
           q.pop();
           ans.push_back(node);
           for(auto it: graphRev[node])
           {
               ind[it]--;
               if(ind[it]==0)
                  q.push(it);
           }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};