class Solution {
public:
    const int mod = 1e9+7;
    long long dp[1000];
    long long solve(int n )
    {
        if(n<=2)return n ;
        if(n==3)return 5;
        
        if(dp[n]!=-1)return dp[n];
       
        return dp[n] = (2*solve(n-1)%mod+solve(n-3)%mod)%mod;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};