class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>&grid , vector<vector<int>>&vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i = 0 ; i < 4 ; i++)
        {
             int nrow = row+drow[i];
             int ncol = col+dcol[i];
             if(nrow>=0 and ncol>=0 and nrow < n and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol]==1)
             {
                 dfs(nrow,ncol,grid,vis);
             }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i = 0 ; i < n ; i++)
       {
           for(int j = 0 ; j < m ; j++)
           {
               if(i==0 || j==0 || i==n-1 || j==m-1)
               {
                   if(grid[i][j]==1)
                   {
                       dfs(i,j,grid,vis);
                   }
               }
           }
       } 
       int cnt = 0 ;
       for(int i = 0 ; i < n ; i++)
       {
           for(int j = 0 ; j < m ; j++)
           {
                if(grid[i][j]==1 and !vis[i][j])
                {
                    cnt++;
                }
                
           }
       } 
       return cnt;
    }
};