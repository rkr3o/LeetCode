class Solution {
public:
    vector<long long> dp;

    long long solve(int ind, vector<int>& cost) {
        if (ind >= cost.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        long long jump1 = cost[ind] + solve(ind + 1, cost);
        long long jump2 = cost[ind] + solve(ind + 2, cost);
        dp[ind] = min(jump1, jump2);
        return dp[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), -1);
        long long ans = min(solve(0, cost), solve(1, cost));
        return static_cast<int>(ans);
    }
};
