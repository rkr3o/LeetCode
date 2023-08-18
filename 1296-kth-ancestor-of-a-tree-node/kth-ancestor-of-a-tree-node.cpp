#include <vector>
using namespace std;

class TreeAncestor {
private:
    vector<vector<int>> dp; // dp[i][j] stores the 2^j-th ancestor of node i
    int maxLog; // The maximum power of 2 needed for dp

public:
    TreeAncestor(int n, vector<int>& parent) {
        maxLog = 0;
        while ((1 << maxLog) <= n) {
            maxLog++;
        }

        dp.assign(n, vector<int>(maxLog, -1));

        // Initialize the 0-th ancestor to the parent array
        for (int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
        }

        // Calculate the dp table for other ancestors
        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j - 1] != -1) {
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < maxLog; j++) {
            if (k & (1 << j)) {
                node = dp[node][j];
                if (node == -1) {
                    break; // k exceeds available ancestors
                }
            }
        }
        return node;
    }
};
