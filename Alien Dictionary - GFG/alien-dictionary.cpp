//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    // topo sort algo to find the ordering of characters of alien dictionary
    private:
    vector<int> topoSort(int K, vector<int> adj[]) {
       
       int indeg[K]={0};
       for(int i=0;i<K;i++)
       {
           for(auto it: adj[i])   // calculate the indegree
             indeg[it]++;
       }
       
       queue<int> q;
       vector<int> ans;
       
       for(int i=0;i<K;i++)
       {
           if(indeg[i]==0)      // if indegree is 0 push it into queue
              q.push(i);
       }
       
       while(!q.empty())
       {
           int node = q.front();
           q.pop();
           ans.push_back(node);
           for(auto it: adj[node])
           {
               indeg[it]--;              // for every adj node , reduce the indegree 
               if(indeg[it]==0)          // and if it become 0 push it into queue
                 q.push(it);
           }
       }
       return ans;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        
        // constructing the directed graph in the form 0,1,..,N-1
        vector<int> adj[K];
        for(int i=0;i<N-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int ptr=0;ptr<len;ptr++)
            {
                if(s1[ptr]!=s2[ptr])
                {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K,adj);
        string ans="";
        for(auto it: topo)
        {
            ans = ans + char(it +'a');    // convrting number back into character
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends