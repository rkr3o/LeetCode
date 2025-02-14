class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int n = s.size();

        if (numRows == 1) return s;

        for (int j = 0; j < numRows; j++) {
            bool isZigzagDown = true;

            for (int i = j; i < n; ) {
                ans += s[i];
                if (j == 0 || j == numRows - 1) {
                    i += (numRows - 1) * 2;
                } else {
                    if (isZigzagDown) {
                        i += (numRows - j - 1) * 2;
                    } else {
                        i += (j * 2);
                    }
                    isZigzagDown = !isZigzagDown;
                }
            }
        }
        return ans;
    }
};
