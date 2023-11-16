class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col] = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid);
            }
        }
    }

    void dfs2(int row, int col, int& cnt, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col] = 0;
        cnt++;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] == 1) {
                dfs2(nrow, ncol, cnt, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        //             if (grid[i][j] == 1) {
        //                 dfs(i, j, grid);
        //             }
        //         }
        //     }
        // }
        int maxima = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    dfs2(i, j, cnt, grid);
                    maxima = max(maxima, cnt);
                }
            }
        }
        return maxima;
    }
};
