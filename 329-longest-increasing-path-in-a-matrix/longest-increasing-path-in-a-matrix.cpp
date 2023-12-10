class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1,0, -1};
        int maxLen = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] > grid[row][col]) {
                int len = 1 + solve(nrow, ncol, grid, dp);
                maxLen = max(maxLen, len);
            }
        }
        dp[row][col] = maxLen;
        return maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxima = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxima = max(maxima, solve(i, j, matrix, dp));
            }
        }
        return maxima;
    }
};