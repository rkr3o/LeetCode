class Solution {
public:
    int dfs(int row , int col , int n , int m,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int cnt = 0 ;
        if(dp[row][col]!=-1)return dp[row][col];
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i = 0 ; i < 4 ; i++)
        {
            int nrow=row+drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 and ncol >=0 and nrow<n and ncol < m and matrix[nrow][ncol]>matrix[row][col])
            {
                cnt = max(cnt,dfs(nrow,ncol,n,m , matrix,dp));
            }
        }
        return dp[row][col] = cnt+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {   
        int n = matrix.size();
        int m = matrix[0].size();
        int maxima = 0 ;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int path = dfs(i,j,n,m,matrix,dp);
                maxima = max(maxima,path);
            }
        }
        return maxima;
    }
};