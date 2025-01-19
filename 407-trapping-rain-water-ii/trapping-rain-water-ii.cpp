#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if (n == 0) return 0;
        int m = heightMap[0].size();
        if (m == 0) return 0;

        // Min-heap to process cells in increasing order of height
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Add all boundary cells to the priority queue
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][m - 1], i, m - 1});
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[n - 1][j], n - 1, j});
            visited[0][j] = visited[n - 1][j] = true;
        }

        // Directions for exploring neighbors (up, down, left, right)
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int waterTrapped = 0;

        // Process cells in the priority queue
        while (!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();

            // Explore all 4 neighbors
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d];
                int ny = y + dirs[d + 1];

                // Skip out-of-bound or already visited cells
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
                    continue;

                // Calculate trapped water for the neighbor
                waterTrapped += max(0, height - heightMap[nx][ny]);

                // Push the neighbor into the queue with the updated height
                pq.push({max(height, heightMap[nx][ny]), nx, ny});
                visited[nx][ny] = true;
            }
        }

        return waterTrapped;
    }
};
