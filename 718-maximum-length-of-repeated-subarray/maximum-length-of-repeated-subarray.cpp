class Solution {
public:
    int solve(vector<int>& S1, vector<int>& S2) {
        int n = S1.size();
        int m = S2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (S1[i - 1] == S2[j - 1]) {
                    int val = 1 + dp[i - 1][j - 1];
                    dp[i][j] = val;
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1, nums2);
    }
};
