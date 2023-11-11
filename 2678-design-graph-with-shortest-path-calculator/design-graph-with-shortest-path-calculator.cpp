class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
         adj.resize(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
         adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) 
    {
     int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (auto v : adj[u]) {
                int newDist = dist[u] + v.second;
                if (newDist < dist[v.first]) {
                    dist[v.first] = newDist;
                    pq.push({newDist, v.first});
                }
            }
        }
        return (dist[node2] == INT_MAX) ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */