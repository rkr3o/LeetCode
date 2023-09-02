class Solution {
public:
    using ll = long long int;

    ll solve(vector<int>& nums, vector<int>& cost, ll median) {
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i] - median) * cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> v;
        ll total = 0;
        for (int i = 0; i < n; ++i) {
            total += cost[i];
            v.push_back({nums[i], cost[i]});
        }
        sort(v.begin(), v.end());
        int i = 0;
        ll sum = 0;
        ll median = 0; // Initialize median
        while (i < n && sum < (total + 1) / 2) {
            median = v[i].first;
            sum += v[i].second; // Accumulate the cost
            i++;
        }

        return solve(nums, cost, median);
    }
};