#include <string>

class Solution {
public:
    int calculate(string s) {
        int total = 0;
        int num = 0;
        int prevNum = 0;
        char sign = '+';

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (sign == '+' || sign == '-') {
                    total += prevNum;
                    prevNum = (sign == '+') ? num : -num;
                } else if (sign == '*') {
                    prevNum *= num;
                } else if (sign == '/') {
                    prevNum /= num;
                }

                num = 0;
                sign = c;
            }
        }

        total += prevNum;
        return total;
    }
};
