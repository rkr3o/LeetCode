class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int sr = entrance[0];
        int sc = entrance[1];
        queue<pair<pair<int, int>, int>> q;
        q.push({{sr, sc}, 0});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && maze[nrow][ncol] == '.') {
                    if (nrow == 0 || nrow == n - 1 || ncol == 0 || ncol == m - 1) {
                        return steps + 1;
                    } else {
                        q.push({{nrow, ncol}, steps + 1});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        
        return -1;
    }
};
