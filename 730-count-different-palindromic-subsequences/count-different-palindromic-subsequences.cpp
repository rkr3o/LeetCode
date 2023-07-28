class Solution {
public:
    const int MOD = 1e9 + 7;

    long long int solve(string& s, int i, int j, vector<vector<long long int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == j)
            return dp[i][j] = 1;

        if (s[i] == s[j]) {
            int left = i + 1;
            int right = j - 1;

            while (left <= right && s[i] != s[left])
                ++left;
            while (left <= right && s[i] != s[right])
                --right;

            if (left > right) {
                dp[i][j] = (2LL * solve(s, i + 1, j - 1, dp) + 2) % MOD;
            } else if (left == right) {
                dp[i][j] = (2LL * solve(s, i + 1, j - 1, dp) + 1) % MOD;
            } else {
                dp[i][j] = (2LL * solve(s, i + 1, j - 1, dp) - solve(s, left + 1, right - 1, dp) + MOD) % MOD;
            }
        } else {
            dp[i][j] = (solve(s, i + 1, j, dp) + solve(s, i, j - 1, dp) - solve(s, i + 1, j - 1, dp) + MOD) % MOD;
        }

        return dp[i][j];
    }

    int countPalindromicSubsequences(string s) {
        int n = s.length();

        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));

        return static_cast<int>(solve(s, 0, n - 1, dp));
    }
};
