class Solution {
public:
    vector<int> ans;
    unordered_set<int> st;
    void solve(int src, map<int, vector<int>>& mp, unordered_set<int>& st) {
        ans.push_back(src);
        st.insert(src);
        for (auto x : mp[src]) {
            if (st.find(x) == st.end()) {
                solve(x, mp, st);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> mp;
        for (auto x : adjacentPairs) {
            int u = x[0];
            int v = x[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int x = 0;
        for (auto& entry : mp) {
            if (entry.second.size() == 1) {
                x = entry.first;
                break;
            }
        }
        solve(x, mp, st);
        return ans;
    }
};
