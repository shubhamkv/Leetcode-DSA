//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int n= s.size();
	    int odd=0;
	    int even=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='1')
	        {
	            if(i%2==0)
	              even++;
	            else
	              odd++;
	        }
	    }
	    
        if(abs(even-odd)%3 == 0 )
          return 1;
          
        return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends