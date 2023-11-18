class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n];
        for (auto x : redEdges) {
            adj[x[0]].push_back({x[1], 0});
        }
        for (auto x : blueEdges) {
            adj[x[0]].push_back({x[1], 1});
        }
        vector<vector<int>> vis(n, vector<int>(2, 0));
        vector<int> ans(n, -1);
        queue<pair<int, pair<int, int>>> q; // node steps color
        vis[0][0] = 1;
        vis[0][1] = 1;
        q.push({0, {0, -1}});
        ans[0] = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second.first;
            int color = q.front().second.second;
            q.pop();

            for (auto x : adj[node]) {
                int adjNode = x.first;
                int currentColor = x.second;

                if (!vis[adjNode][currentColor] and color != currentColor) {
                    q.push({adjNode, {steps + 1, currentColor}});
                    vis[adjNode][currentColor] = 1;

                    // Move the following lines outside the loop
                }
            }

            // Update ans outside the loop
            if (ans[node] == -1) {
                ans[node] = steps;
            }
        }

        return ans;
    }
};
