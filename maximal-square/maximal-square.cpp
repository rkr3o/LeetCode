class Solution {
public:
    int solve(int row, int col, int& maxima, vector<vector<char>>& matrix,vector<vector<int>>&dp) {
        if (row < 0 || col < 0)
            return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int up = solve(row - 1, col, maxima, matrix,dp);
        int left = solve(row, col - 1, maxima, matrix,dp);
        int diagonal = solve(row - 1, col - 1, maxima, matrix,dp);

        if (matrix[row][col] == '1') {
            int ans = 1 + min({up, left, diagonal});
            maxima = max(maxima, ans);
            return dp[row][col] = ans;
        } else {
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int maxima = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(n - 1, m - 1, maxima, matrix,dp);

        return maxima * maxima;
    }
};
