class Solution {
public:
    double solve(int n, int k, int row, int col, vector<vector<vector<double>>>& dp) {
        if (k == 0) return 1.0;
        if (dp[row][col][k] != -1.0) return dp[row][col][k];
        double ans = 0.0;
        int drow[]={1,1,-1,-1,2,-2,2,-2};
        int dcol[]={2,-2,2,-2,1,1,-1,-1};
        for (int i = 0; i < 8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n) {
                ans += solve(n, k - 1, nrow, ncol, dp) / 8.0;
            }
        }
        return dp[row][col][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        return solve(n, k, row, column, dp);
    }
};
