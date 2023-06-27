class Solution {
public:
    void solve(int n , int open ,int close ,string &s ,vector<string>&ans)
    {
        if(open==0 and close == 0)
        {
            ans.push_back(s);
            return ;
        }

        if(open>0)
        {
            s.push_back('(');
            solve(n,open-1,close,s,ans);
            s.pop_back();
        }
        if(close >0)
        {
            if(open < close)
            {
                s.push_back(')');
                solve(n,open,close-1,s,ans);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) 
    {
         vector<string>ans;
         string s ;
         solve(n,n,n,s,ans);
         return ans;    
    }
};