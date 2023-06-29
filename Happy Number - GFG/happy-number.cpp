//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int N){
        // code here
        if(N==1 || N==7)
          return 1;
        if(N==2 || N==3 || N==4 || N==5 || N==6 || N==8 || N==9)
          return 0;
          
        int sum=0;
        while(N!=0)
        {
            int rem=N%10;
            sum+=rem*rem;
            N/=10;
        }
        return isHappy(sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends