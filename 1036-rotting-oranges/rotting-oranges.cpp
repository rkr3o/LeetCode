class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int maxima = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int steps = q.front().first;
                int row = q.front().second.first;
                int col = q.front().second.second;
                maxima = max(maxima, steps);
                q.pop();
                
                for(int j = 0; j < 4; j++) {
                    int nrow = row + drow[j];
                    int ncol = col + dcol[j];
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                        q.push({steps + 1, {nrow, ncol}});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 1) {
                    return -1;
                }
            }
        }
        
        return maxima;
    }
};
