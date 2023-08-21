class Solution {
public:
 const int mod = 1e9 + 7;

    int solve(int n, vector<int>& coins, vector<int>& marks, int t, vector<vector<int>>& dp) {
        if (n < 0) {
            return (t == 0);
        }
        if (dp[n][t] != -1) {
            return dp[n][t];
        }
        
        int ways = 0;
        for (int count = 0; count <= coins[n]; count++) {
            if (t >= count * marks[n]) {
                ways = (ways + solve(n - 1, coins, marks, t - count * marks[n], dp)) % mod;
            } else {
                break;
            }
        }
        
        return dp[n][t] = ways;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<int> coins(n), marks(n);
        for (int i = 0; i < n; i++) {
            coins[i] = types[i][0];
            marks[i] = types[i][1];
        }
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, coins, marks, target, dp);
    }
};