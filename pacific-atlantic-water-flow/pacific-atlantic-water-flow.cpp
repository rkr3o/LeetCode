class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& visited, int prev_height) {
        int n = heights.size();
        int m = heights[0].size();
        
        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] || heights[row][col] < prev_height) {
            return;
        }
        
        visited[row][col] = 1;
        
        dfs(row - 1, col, heights, visited, heights[row][col]);
        dfs(row + 1, col, heights, visited, heights[row][col]);
        dfs(row, col - 1, heights, visited, heights[row][col]);
        dfs(row, col + 1, heights, visited, heights[row][col]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> result;
        
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific, INT_MIN);
            dfs(i, m - 1, heights, atlantic, INT_MIN);
        }
        
        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific, INT_MIN);
            dfs(n - 1, j, heights, atlantic, INT_MIN);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
