#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int row, int col, int k, vector<vector<vector<int>>>& dp) {
        if (row == 3 && (col == 0 || col == 2)) return 0;
        if (k == 0) return 1;
        if (dp[row][col][k] != -1) return dp[row][col][k];

        int ways = 0;
        int drow[] = {1, 1, -1, -1, 2, -2, 2, -2};
        int dcol[] = {2, -2, 2, -2, 1, 1, -1, -1};

        for (int i = 0; i < 8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < 4 && ncol < 3) {
                ways = (ways + solve(nrow, ncol, k - 1, dp)) % mod;
            }
        }

        return dp[row][col][k] = ways;
    }

    int knightDialer(int n) {
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        int ans = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 3 && (j == 0 || j == 2)) continue;
                ans = (ans + solve(i, j, n - 1, dp)) % mod;
            }
        }

        return ans;
    }
};
