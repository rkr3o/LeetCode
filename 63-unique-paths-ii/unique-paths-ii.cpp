class Solution {
public:
    int dp[100][100];
    
    int solve(int row, int col, int n, int m, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 1) {
            return 0;
        }
        if (row == n - 1 && col == m - 1) {
            return 1;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int right = solve(row, col + 1, n, m, grid);
        int down = solve(row + 1, col, n, m, grid);
        return dp[row][col] = right + down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return 0;  // If the start or end is blocked, there are no paths.
        }
        return solve(0, 0, n, m, grid);
    }
};
