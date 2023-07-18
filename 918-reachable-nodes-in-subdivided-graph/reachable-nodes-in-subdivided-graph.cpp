#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // Create an adjacency matrix to represent the graph
        vector<vector<int>> graph(n, vector<int>(n, -1));
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cnt = edge[2];
            graph[u][v] = cnt;
            graph[v][u] = cnt;
        }
        
        // Keep track of visited nodes
        vector<bool> visited(n, false);
        
        // Use a priority queue to store nodes based on the remaining moves
        priority_queue<pair<int, int>> pq;
        pq.push({maxMoves, 0});  // (movesRemaining, node)
        
        // Keep track of the nodes that are reachable
        int reachable = 0;
        
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            int movesRemaining = curr.first;
            int node = curr.second;
            
            if (visited[node]) {
                continue;
            }
            
            visited[node] = true;
            reachable++;
            
            for (int i = 0; i < n; i++) {
                if (graph[node][i] != -1) {
                    int cnt = graph[node][i];
                    int remaining = movesRemaining - cnt - 1;
                    
                    // Add the remaining moves to reach the next node
                    if (remaining >= 0) {
                        reachable += cnt;
                        
                        // Add the remaining moves and the next node to the priority queue
                        pq.push({remaining, i});
                        
                        // Update the remaining moves for the current node
                        graph[i][node] -= min(cnt, movesRemaining);
                        graph[node][i] -= min(cnt, movesRemaining);
                    } else {
                        // No more moves remaining to reach the next node
                        reachable += movesRemaining;
                        
                        // Update the remaining moves for the current node
                        graph[i][node] -= movesRemaining;
                        graph[node][i] -= movesRemaining;
                    }
                }
            }
        }
        
        return reachable;
    }
};
