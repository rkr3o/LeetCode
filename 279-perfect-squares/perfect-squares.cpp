class Solution {
public:
     int dp[10000];
     int solve(int t) {
        if (t == 0) return 0;
        if (dp[t] != -1) return dp[t];

        int ans = INT_MAX;
        for (int i = 1; i*i <= t; i++) {
            int val = 1 + solve(t - i * i);
            ans = min(ans, val);
        }
        return dp[t] = ans;
    }

    int numSquares(int n) {
       memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
