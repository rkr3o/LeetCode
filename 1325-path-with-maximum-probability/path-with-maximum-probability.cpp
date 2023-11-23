
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end) {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        vector<double> dist(n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, src});
        dist[src] = 1.0;

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end) {
                return dist[end];
            }

            for (auto x : adj[node]) {
                int adjNode = x.first;
                double edgeProb = x.second;

                if (dist[adjNode] < prob * edgeProb) {
                    dist[adjNode] = prob * edgeProb;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return 0.0;
    }
};