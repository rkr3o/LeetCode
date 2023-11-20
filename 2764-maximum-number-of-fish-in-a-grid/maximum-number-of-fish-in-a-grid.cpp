class Solution {
public:
    void solve(int row,  int col , int &cnt , vector<vector<int>>&vis , vector<vector<int>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        cnt+=grid[row][col];
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        for(int i = 0 ; i < 4 ; i++)
        {
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 and ncol>=0 and nrow < n and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol]>0)
            {
                solve(nrow,ncol,cnt,vis,grid);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxima = 0 ;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                if(grid[i][j]==0)continue;
                if(grid[i][j] >0 and !vis[i][j])
                {
                    int cnt = 0;
                    solve(i,j,cnt,vis,grid);
                    maxima=max(maxima,cnt);
                }
            }
        }
        return maxima;
    }
};