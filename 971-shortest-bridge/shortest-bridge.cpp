
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int, int>>& q) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        q.push({row, col});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        bool found = false;

        // Find the first island using DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, vis, q);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        int steps = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        bool foundSecondIsland = false;

        // Perform BFS to find the second island and count the minimum number of flips needed
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m and !vis[nrow][ncol]) 
                    {
                            if (grid[nrow][ncol] == 1) 
                            {
                               return steps;
                            }
                            q.push({nrow, ncol});
                            vis[nrow][ncol] = 1;
                     
                    }
                }
              //  if (foundSecondIsland) break;
            }
           // if (foundSecondIsland) break;
            steps++;
        }
        return -1 ; // Subtract 1 as the last step is not needed to connect the islands
    }
};