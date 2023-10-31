class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<int>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[row][col]=1;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i = 0 ; i < 4 ; i++)
        {
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 and ncol >=0 and nrow < n and ncol < m and grid[nrow][ncol]==0 and !vis[nrow][ncol])
            {
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         int cnt = 0 ;
         for(int i = 0 ; i < n ; i++)
         {
             for(int j = 0 ; j < m ; j++)
             {
                   if(i==0 || j==0 || i==n-1 || j==m-1)
                   {
                       if(grid[i][j]==0 and !vis[i][j])
                       {
                           dfs(i,j,vis,grid);
                       }
                   }
             }
         }
        for(int i = 0 ; i < n ; i++)
         {
             for(int j = 0 ; j < m ; j++)
             {
                if(grid[i][j]==0 and !vis[i][j])
                    {
                        dfs(i,j,vis,grid);
                        cnt++;
                    }
                
             }
         }
         return cnt;
    }
};