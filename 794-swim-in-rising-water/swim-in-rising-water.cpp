class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int result = 0; // Store the result, which is the minimum time needed.
        while (!pq.empty()) {
            int element = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            // Update the result with the maximum of the current element and result.
            result = max(result, element);
            // If we reached the bottom-right corner, return the result.
            if (row == n - 1 && col == n - 1) {
                return result;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && !vis[nrow][ncol]) {
                    pq.push({grid[nrow][ncol], {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1; // This should not be reached if the grid is valid.
    }
};