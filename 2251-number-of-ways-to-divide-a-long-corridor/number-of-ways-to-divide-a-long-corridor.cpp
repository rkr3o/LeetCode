class Solution {
public:
    const int mod = 1e9+7;
    int dp[100006][5];
    int solve(int ind , int seats , string &s)
    {
        if(seats>2 || ind>s.size())return 0;
        if(ind==s.size())return seats==2;
        if(dp[ind][seats]!=-1)return dp[ind][seats];
        if(s[ind]=='S')seats++;
       // if(seats>2)return 0;
        int ans = solve(ind+1,seats,s);
        if(seats==2)
        {
            ans+=solve(ind+1,0,s);
            ans%=mod;
        }
        return dp[ind][seats] = ans%mod;
    }
    int numberOfWays(string corridor) {
        int cnt = count(begin(corridor),end(corridor),'S');
        if(cnt%2!=0)return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,corridor);
    }
};