class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        //dp[i] = whether the substring ending at index i is a palindrome or not.

        int count = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1])) {
                    dp[j] = 1;
                    count++;
                } else {
                    dp[j] = 0;
                }
            }
        }

        return count;
    }
};