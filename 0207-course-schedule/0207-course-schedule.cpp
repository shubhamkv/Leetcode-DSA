class Solution {   
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> ind(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it: adj[i])
                ind[it]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(ind[i]==0)
                q.push(i);
        }
        
        int cnt=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node])
            {
                ind[it]--;
                if(ind[it]==0)
                    q.push(it);
            }
        }
        
        if(cnt==numCourses)
            return true;
        
        return false;
    }
};