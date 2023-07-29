class Solution {
public:
    int expandFromMiddle(const string& s, int st, int end) {
        int n = s.size();
        while (st >= 0 && end < n && s[st] == s[end]) {
            st--;
            end++;
        }
        return end - st - 1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int maxima = 1;
        int start = 0; // Starting index of the longest palindromic substring

        for (int i = 0; i < n; i++) {
            int even = expandFromMiddle(s, i, i);
            int odd = expandFromMiddle(s, i, i + 1);

            int cur = max(even, odd);

            if (cur > maxima) {
                maxima = cur;
                start = i - (cur - 1) / 2; // Calculate the starting index of the new longest palindrome
            }
        }

        // Extract the longest palindromic substring
        return s.substr(start, maxima);
    }
};