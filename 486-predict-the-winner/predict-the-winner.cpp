class Solution
{
    public:
        long long solve(int i, int j, vector<int> &arr, int n, vector<vector< long long>> &dp)
        {
            if (i > j) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            long long startPick = arr[i] + min(solve(i + 2, j, arr, n, dp), solve(i + 1, j - 1, arr, n, dp));
            long long endPick = arr[j] + min(solve(i, j - 2, arr, n, dp), solve(i + 1, j - 1, arr, n, dp));
            return dp[i][j] = max(startPick, endPick);
        }
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector < long long>> dp(n, vector < long long > (n, -1));
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);	// Calculate the sum of all numbers
        long long player1Score = solve(0, n - 1, nums, n, dp);
        return player1Score >= (totalSum + 1) / 2;
    }
};