class Solution {
public:   
    int numberOfWays(int st, int end, int k) 
    {
        vector<vector<int>> dp(1005,vector<int> (3005,0));
        int mod = 1e9 +7;
        dp[0][st+1000] = 1;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=3000;j++)
                dp[i][j] = (dp[i-1][j+1]+dp[i-1][j-1])%mod;
        }
        return dp[k][end+1000];
    }
};