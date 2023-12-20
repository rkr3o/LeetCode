class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodedLength = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                int digit = ch - '0';
                decodedLength *= digit;
            } else {
                decodedLength++;
            }
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (isdigit(ch)) {
                int digit = ch - '0';
                decodedLength /= digit;
                k %= decodedLength;
            } else {
                if (k == 0 || k == decodedLength) {
                    return string(1, ch);
                }
                decodedLength--;
            }
        }

        return "";
    }
};
