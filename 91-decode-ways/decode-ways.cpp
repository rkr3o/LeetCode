class Solution {
public:
    int dp[102];
    int solve(int ind , string &s)
    {
        if(ind==s.size())return 1;
        if(s[ind]=='0')return 0 ;
        if(dp[ind]!=-1)return dp[ind];
        int ans = 0 ;
        ans+=solve(ind+1,s);
        if(ind+1<s.size())
        {
            int twoDigits = (s[ind] - '0') *10 + (s[ind + 1] - '0');
            if(twoDigits>=10 and twoDigits<=26)
            {
                ans += solve(ind+2,s);
            }
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};