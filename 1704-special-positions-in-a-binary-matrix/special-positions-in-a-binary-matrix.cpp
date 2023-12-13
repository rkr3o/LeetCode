#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<int> rowSum(n, 0);
        vector<int> colSum(m, 0);

        // Calculate row and column sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        // Check for special elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
