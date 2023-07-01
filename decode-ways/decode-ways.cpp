class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = (s[n - 1] != '0') ? 1 : 0; // Handle the base case for the last character

        for (int i = n - 2; i >= 0; i--)
        {
            // Check if the current character is not '0' and can be decoded individually
            if (s[i] != '0')
            {
                dp[i] = dp[i + 1];
            }

            // Check if the current and next characters can be decoded as a two-digit number
            int twoDigits = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (twoDigits >= 10 && twoDigits <= 26)
            {
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};
