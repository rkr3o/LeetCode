class Solution {
public:
    const int mod = 1e9+7;
    int dp[1001];
    int solve(int n)
    {
        if(n<=2)return n ;
        if(n==3)return 5;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = (2*solve(n-1)%mod+solve(n-3)%mod)%mod;
    }
    int numTilings(int n) {
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i = 4 ; i <= n ; i++)
        {
            dp[i]=(2*dp[i-1]%mod+dp[i-3]%mod)%mod;
        }
        return dp[n];
    }
};