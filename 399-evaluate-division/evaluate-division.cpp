class Solution {
public:
    void dfs(string src, unordered_set<string>& vis, string& dst, unordered_map<string, vector<pair<string, double>>>& mp, double& res, double pd) {
        if (vis.find(src) != vis.end())
            return;

        vis.insert(src);

        if (src == dst) {
            res = pd;
            return;
        }

        for (auto x : mp[src]) {
            string v = x.first;
            double val = x.second;
            dfs(v, vis, dst, mp, res, pd * val);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;

        // Create the graph
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            mp[u].push_back({v, val});
            mp[v].push_back({u, 1.0 / val});
        }

        // Store answers
        vector<double> ans;
        for (auto x : queries) {
            string src = x[0];
            string dst = x[1];
            double result = -1.0;
            double product = 1;

            if (mp.find(src) != mp.end()) {
                unordered_set<string> st;
                dfs(src, st, dst, mp, result, product);
            }

            ans.push_back(result);
        }

        return ans;
    }
};
