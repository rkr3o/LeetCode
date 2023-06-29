class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int maxima = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    if (matrix[i][j] == '1') {
                        int up = dp[i-1][j];
                        int left = dp[i][j-1];
                        int diagonal = dp[i-1][j-1];
                        dp[i][j] = 1 + min({up, left, diagonal});
                    } else {
                        dp[i][j] = 0;
                    }
                }
                maxima = max(maxima, dp[i][j]);
            }
        }
        
        return maxima * maxima;
    }
};
