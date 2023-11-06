class Solution {
public:
    int dp[100][100];
    int solve(int row , int col , int n , int m)
    {
        if(row<0 || col < 0 || row>=n || col>=m)return 0;
        if(row==n-1 and col==m-1)
           return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int left = solve(row+1,col,n,m);
        int down = solve(row,col+1,n,m);
        return dp[row][col] =  left+down;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};