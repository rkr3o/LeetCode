#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        int n = pairs.size();
        std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int cur = std::numeric_limits<int>::min();
        for (const auto& pair : pairs) {
            int head = pair[0];
            int tail = pair[1];
            if (head > cur) {
                cur = tail;
                ans++;
            }
        }

        return ans;
    }
};
