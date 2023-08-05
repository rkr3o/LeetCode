class Solution {
public:
    void solve(int start, int n, int k, vector<int>& ds, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = start; i <= n; i++) {
            ds.push_back(i);
            solve(i + 1, n, k - 1, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, n, k, ds, ans);
        return ans;
    }
};
