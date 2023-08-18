class Solution {
    bool isSafe(int row, int col, vector<string>& parts, int n) {
        for (int i = 0; i < n; i++) {
            if (parts[i][col] == 'Q') {
                return false; // Check vertical threats
            }
            if (parts[row][i] == 'Q') {
                return false; // Check horizontal threats
            }
        }
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int newRow = row + i;
                int newCol = col + j;
                while (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                    if (parts[newRow][newCol] == 'Q') {
                        return false; // Check diagonal threats
                    }
                    newRow += i;
                    newCol += j;
                }
            }
        }
        
        return true;
    }
    
    void solve(int col, vector<vector<string>>& ans, vector<string>& parts, int n) {
        if (col == n) {
            ans.push_back(parts);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, parts, n)) {
                parts[row][col] = 'Q';
                solve(col + 1, ans, parts, n);
                parts[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> parts(n, string(n, '.'));
        solve(0, ans, parts, n);
        return ans;
    }
};
