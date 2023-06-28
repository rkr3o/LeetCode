#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> indegree(n, vector<int>(m, 0));
        vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Compute the indegree of each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (const auto& dir : directions) {
                    int newRow = i + dir[0];
                    int newCol = j + dir[1];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] > matrix[i][j]) {
                        indegree[newRow][newCol]++;
                    }
                }
            }
        }
        
        // Find the cells with indegree 0 and enqueue them
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (indegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // Perform BFS
        int longestPath = 0;
        while (!q.empty()) {
            int size = q.size();
            longestPath++;
            
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for (const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && matrix[newRow][newCol] > matrix[row][col]) {
                        indegree[newRow][newCol]--;
                        
                        if (indegree[newRow][newCol] == 0) {
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
        }
        
        return longestPath;
    }
};
