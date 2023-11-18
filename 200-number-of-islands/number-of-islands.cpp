class Solution {

    void dfs(int row , int col , vector<vector<char>>&grid , vector<vector<int>>&vis)
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

            if(nrow>=0 and ncol >=0 and nrow<n and ncol < m and grid[nrow][ncol]=='1' and !vis[nrow][ncol])
            {
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
            int n = grid.size();
            int cnt = 0;
            int m = grid[0].size();
            vector<vector<int>>vis(n,vector<int>(m,0));
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < m ; j++)
                {
                    if(grid[i][j]=='1' and !vis[i][j])
                    {
                        dfs(i,j,grid,vis);
                        cnt++;
                    }
                }
            }  

            return cnt;
    }
};