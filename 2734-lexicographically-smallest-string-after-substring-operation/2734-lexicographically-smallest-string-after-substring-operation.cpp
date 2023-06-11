class Solution {
public:
    string smallestString(string s) {
        
        int n = s.size();
        int i=0;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='a')
            {
                for(int j=i;j<n;j++)
                {
                    if(s[j]=='a')
                      break;
                    else
                      s[j]--;        // we replace the char which comes before from present char by doing this
                }
                flag = true;
                break;
            }
        }
        if(!flag)
          s[n-1]='z';

        return s;
    }
};