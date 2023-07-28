class Solution {
public:

const int MOD = 1e9+7;


// Top-down DP function to calculate the number of different non-empty palindromic subsequences
long long int solve(string& s, int i, int j, vector<vector<long long int>>& dp) {
    // Base case: if the start index i is greater than the end index j, return 0
    if (i > j)
        return 0;

    // If the result for the current subproblem is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // Base case: if start and end indices are the same, return 1 as a single character is a palindrome
    if (i == j)
        return dp[i][j] = 1;

    // If the characters at the current positions are the same
    if (s[i] == s[j]) {
        int left = i + 1;
        int right = j - 1;

        // Find the first and last occurrence of the character in between
        while (left <= right && s[i] != s[left])
            ++left;
        while (left <= right && s[i] != s[right])
            --right;

        if (left > right) {
            // If there is no occurrence in between, we have:
            // Two characters of the same kind + the result of the inner subsequence
            dp[i][j] = (2LL * solve(s, i + 1, j - 1, dp) + 2) % MOD;
        } else if (left == right) {
            // If there is only one occurrence in between, we have:
            // Two characters of the same kind + the result of the inner subsequence
            dp[i][j] = (2LL * solve(s, i + 1, j - 1, dp) + 1) % MOD;
        } else {
            // If there are multiple occurrences in between, we have:
            // Two characters of the same kind + the result of the inner subsequence
            // minus the result of overlapping subsequence
            dp[i][j] = (2LL * solve(s, i + 1, j - 1, dp) - solve(s, left + 1, right - 1, dp) + MOD) % MOD;
        }
    } else {
        // If the characters at the current positions are different,
        // then the result is the same as the result of the inner subsequence
        // without considering the current characters
        dp[i][j] = (solve(s, i + 1, j, dp) + solve(s, i, j - 1, dp) - solve(s, i + 1, j - 1, dp) + MOD) % MOD;
    }

    return dp[i][j];
}

    int countPalindromicSubsequences(string s) {
       int n = s.length();

     // Create a 2D DP array to store the count of palindromic subsequences
     vector<vector<long long int>> dp(n, vector<long long int>(n, -1));

    // Call the top-down DP function with the whole string (0 to n-1)
      return static_cast<int>(solve(s, 0, n - 1, dp));
    }
};