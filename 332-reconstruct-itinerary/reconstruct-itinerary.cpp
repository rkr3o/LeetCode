class Solution {
public:
    void dfs(string src, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& result) {
        while (!graph[src].empty()) {
            string dest = graph[src].top();
            graph[src].pop();
            dfs(dest, graph, result);
        }
        result.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        // Build the graph
        for (auto ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> result;
        dfs("JFK", graph, result);

        reverse(result.begin(), result.end());
        return result;
    }
};
