//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans;
		    int n=A.size();
		    map<char,int>mp;
		    queue<char>q;
		    for(int i=0;i<n;i++)
		    {
		        mp[A[i]]++;
		        q.push(A[i]);
		        while(!q.empty() && mp[q.front()]>1){
		            q.pop();
		        }
		        if(!q.empty())
		            ans+=q.front();
		        else
		            ans+='#';
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends