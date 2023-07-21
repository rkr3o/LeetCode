#include <vector>
#include <algorithm>

class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        int n = pairs.size();
        if (n == 1) return 1;

        int maxima = 0 ;

        // Sort pairs based on the second element of each pair.
        std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int end = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pairs[i][0] > end) {
                maxima++;
                end = pairs[i][1];
            }
        }

        return maxima;
    }
};
