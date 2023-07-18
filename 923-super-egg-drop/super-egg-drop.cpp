class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // Base cases:
        // If there's only one egg, we need to try all floors one by one.
        for (int i = 1; i <= n; i++) {
            dp[1][i] = i;
        }

        // If there's only one floor, we only need one attempt regardless of the number of eggs.
        for (int i = 1; i <= k; i++) {
            dp[i][1] = 1;
        }

        // Bottom-up dynamic programming
        for (int i = 2; i <= k; i++) {
            int x = 1; // Start with the first floor
            for (int j = 2; j <= n; j++) {
                dp[i][j] = INT_MAX;
                // Perform binary search to find the optimal floor to drop the egg
                int left = 1, right = j;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    int broke = dp[i - 1][mid - 1]; // Egg breaks, so we have i - 1 eggs left and mid - 1 floors below.
                    int notBroke = dp[i][j - mid]; // Egg doesn't break, so we have i eggs left and j - mid floors above.
                    int worst = 1 + max(broke, notBroke); // Take the worst case scenario.
                    dp[i][j] = min(dp[i][j], worst); // Find the minimum attempts among all possible x values.
                    if (broke < notBroke) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        return dp[k][n];
    }
};
