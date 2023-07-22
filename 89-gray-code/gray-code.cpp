#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> solve(int n) {
        vector<string> ans;
        if (n == 1) {
            return { "0", "1" };
        }
        
        vector<string> pre = solve(n - 1);
        int x = (int)pre.size();
        for (int i = 0; i < x; ++i) {
            ans.push_back("0" + pre[i]);
        }
        for (int i = x - 1; i >= 0; i--) {
            ans.push_back("1" + pre[i]);
        }

        return ans;
    }

    vector<int> grayCode(int n) {
        vector<string> binaryStrings = solve(n);
        vector<int> grayCodes;
        
        for (const string& binaryStr : binaryStrings) {
            int grayCode = 0;
            for (char c : binaryStr) {
                grayCode = (grayCode << 1) + (c - '0');
            }
            grayCodes.push_back(grayCode);
        }

        return grayCodes;
    }
};
