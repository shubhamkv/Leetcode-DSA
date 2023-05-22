//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    //   ---------------------- DFS Solution ----------------------------------------------
    
//   private:
//     bool dfs(int node, vector<int> adj[], int vis[], int pathVis[])
//     {
//         vis[node]=1;
//         pathVis[node]=1;
        
//         for(auto it: adj[node])
//         {
//             if(!vis[it])
//             {
//                 if(dfs(it,adj,vis,pathVis)==true)
//                   return true;
//             }
//             else if(pathVis[it])
//               return true;
//         }
        
//         pathVis[node]=0;
//         return false;
//     }
//   public:
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<int> adj[]) {
//         // code here
//         int vis[V]={0};
//         int pathVis[V]={0};
        
//         for(int i=0;i<V;i++)
//         {
//             if(!vis[i])
//             {
//                 if(dfs(i,adj,vis,pathVis)==true)
//                   return true;
//             }
//         }
//         return false;
//     }

// ------------------------------- BFS Solution ---------------------------------------
    
    public:
      bool isCyclic(int V, vector<int> adj[]){
          
         int indeg[V]={0};
         for(int i=0;i<V;i++)
         {
           for(auto it: adj[i])   // calculate the indegree
             indeg[it]++;
         }
       
         queue<int> q;
         int cnt=0;
       
         for(int i=0;i<V;i++)
         {
           if(indeg[i]==0)      // if indegree is 0 push it into queue
              q.push(i);
         }
       
         while(!q.empty())
         {
           int node = q.front();
           q.pop();
           cnt++;
           for(auto it: adj[node])
           {
               indeg[it]--;              // for every adj node , reduce the indegree 
               if(indeg[it]==0)          // and if it become 0 push it into queue
                 q.push(it);
           }
         }
         
         if(cnt==V)
           return false;
         return true;
      }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends