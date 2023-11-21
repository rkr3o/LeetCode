class Solution {
    int dfs(int row , int col , vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        if(dp[row][col]!=-1)return dp[row][col];
        for(int i = 0 ; i < 4 ; i++)
        {
             int nrow = row+drow[i];
             int ncol = col+dcol[i];
             if(nrow>=0 and ncol >=0 and nrow<n and ncol<m and matrix[nrow][ncol]>matrix[row][col])
             {
                 cnt = max(cnt,dfs(nrow,ncol,matrix,dp));
             }
        }
        return dp[row][col] = cnt+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
         int n = matrix.size();
         int m = matrix[0].size();
         int maxi = 0 ;
         //vector<vector<int>>vis(n,vector<)
         if(matrix.size()==0)return 0;
         vector<vector<int>>dp(n,vector<int>(m,-1));
         for(int i = 0 ; i < n ; i++)
         {
             for(int j = 0 ; j < m  ; j++)
             {
                   int path = dfs(i,j,matrix,dp);
                   maxi = max(maxi,path);
             }
         }
         return maxi;
    }
};