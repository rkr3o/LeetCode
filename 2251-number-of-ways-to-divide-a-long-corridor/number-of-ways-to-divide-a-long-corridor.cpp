#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int numberOfWays(string corridor) {
        vector<int> seatIndices;
        int cnt = 0;

        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seatIndices.push_back(i);
                cnt++;
            }
        }

        if (cnt % 2 != 0 || cnt == 0) return 0;

        long long res = 1;

        for (int i = 2; i < seatIndices.size(); i += 2) {
            res = (res * (seatIndices[i] - seatIndices[i - 1])) % mod;
        }

        return static_cast<int>(res);
    }
};
 