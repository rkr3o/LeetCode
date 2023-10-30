class Solution {
public:
    const int mod = 1e9+7;
    long long dp[4000][1001];
    int solve(int start, int end, int k) {
        if (k == 0) {
            return (start == end) ? 1 : 0;
        }
        if(dp[start+1000][k]!=-1)return dp[start+1000][k];
        long long steps1 = solve(start + 1, end, k - 1) % mod;
        long long steps2 = solve(start - 1, end, k - 1) % mod;
        return dp[start+1000][k] = (steps1 + steps2) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(startPos, endPos, k);
    }
};
