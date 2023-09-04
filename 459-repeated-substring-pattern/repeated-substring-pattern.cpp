class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n= s.size() ;
        for(int i = 1; i <= n/2 ; i++)
        {
            if(n%i==0)
            {
                string t = s.substr(0,i);
                int times = n/i;
                string p;
                while(times--)
                {
                     p+=t;
                }
                if(s==p)return true;
            }
            
        }
        return false;
    }
};