class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;

        // Create a weighted graph
        vector<pair<int, int>> g[n];
        for (auto r : roads) {
            r[0]--;
            r[1]--;
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }

        vector<int> vis(n, 0);
        queue<int> q;
        vector<int> parent(n, -1);
        q.push(0); // Start BFS from node 0

        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adjNode : g[node]) {
                int edgeNode = adjNode.first;
                int edgeWeight = adjNode.second;
                // ans = min(ans, edgeWeight);
                if(edgeWeight < ans)
                {
                    ans = edgeWeight;
                    parent[edgeNode] = node;
                }

                if (!vis[edgeNode]) {
                    q.push(edgeNode);
                    vis[edgeNode] = 1;
                    
                }
            }
        }

        // Print the path
        cout << "Path: ";
        int current = n - 1;  // End node
        while (current != -1) {
            cout << current << " ";
            current = parent[current];
        }
        cout << endl;

        return ans;
    }
};