class Solution {
public:
    int dp[366];

    int solve(int ind, vector<int>& days, vector<int>& costs) {
        if (ind >= days.size()) return 0;
        if (dp[ind] != -1) return dp[ind];

        int option1 = costs[0] + solve(ind + 1, days, costs);

        int next7 = lower_bound(days.begin(), days.end(), days[ind] + 7) - days.begin();
        int option2 = costs[1] + solve(next7, days, costs);

        int next30 = lower_bound(days.begin(), days.end(), days[ind] + 30) - days.begin();
        int option3 = costs[2] + solve(next30, days, costs);

        return dp[ind] = min({option1, option2, option3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, days, costs);
    }
};
