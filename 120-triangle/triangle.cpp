class Solution {
public:
    int solve(int row,  int col, vector<vector<int>>&v,vector<vector<int>>&dp)
    {
        if(row>=v.size())return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int down = v[row][col]+solve(row+1,col,v,dp);
        int diag = v[row][col]+solve(row+1,col+1,v,dp);
        return dp[row][col] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,triangle,dp);
    }
};