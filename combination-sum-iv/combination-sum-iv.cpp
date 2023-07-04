class Solution {
public:
    int solve(int idx, vector<int>& nums, int t, vector<int>& dp) {
        if (t < 0)
            return 0;
        if (t == 0)
            return 1;

        int ways = 0;
        if (dp[t] != -1)
            return dp[t];

        for (int i = 0; i < nums.size(); i++) {
            ways += solve(i, nums, t - nums[i], dp);
        }

        return dp[t] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(0, nums, target, dp);
    }
};
