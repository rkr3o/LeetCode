class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int maxima = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prevRow(m, 0);  // Previous row
        vector<int> currRow(m, 0);  // Current row
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    currRow[j] = matrix[i][j] - '0';
                } else {
                    if (matrix[i][j] == '1') {
                        int up = prevRow[j];
                        int left = currRow[j-1];
                        int diagonal = prevRow[j-1];
                        currRow[j] = 1 + min({up, left, diagonal});
                    } else {
                        currRow[j] = 0;
                    }
                }
                maxima = max(maxima, currRow[j]);
            }
           prevRow=currRow;  // Update the previous row
        }
        
        return maxima * maxima;
    }
};
