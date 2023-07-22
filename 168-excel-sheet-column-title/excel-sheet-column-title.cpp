class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int, char> mp;
        int i = 1;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            mp[i++] = ch;
        }

        string ans = "";
        while (columnNumber > 0) {
            int remainder = columnNumber % 26;
            if (remainder == 0) {
                ans = 'Z' + ans;
                columnNumber = columnNumber / 26 - 1;
            } else {
                ans = mp[remainder] + ans;
                columnNumber = columnNumber / 26;
            }
        }

        return ans;
    }
};
