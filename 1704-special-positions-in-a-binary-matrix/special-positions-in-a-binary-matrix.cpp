#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Check the row
                    bool hasOtherOneInRow = false;
                    for (int col = 0; col < m; col++) {
                        if (col != j && grid[i][col] == 1) {
                            hasOtherOneInRow = true;
                            break;
                        }
                    }
                    // Check the column
                    bool hasOtherOneInCol = false;
                    for (int row = 0; row < n; row++) {
                        if (row != i && grid[row][j] == 1) {
                            hasOtherOneInCol = true;
                            break;
                        }
                    }
                    // If there is no other '1' in the row and column, increment count
                    if (!hasOtherOneInRow && !hasOtherOneInCol) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};
