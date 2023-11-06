class Solution {
public:
    using ll = long long int;
    ll dp[51][51][51];
    const int mod = 1e9+7;
    int solve(int row , int col , int n , int m , int maxima)
    {
        if(row < 0 || col < 0 || row>=n || col>=m)return 1;
        if(maxima==0)return 0 ;
        if(dp[row][col][maxima]!=-1)return dp[row][col][maxima];
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        ll ans = 0 ;
        for(int i = 0 ; i < 4 ; i++)
        {
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            (ans+=solve(nrow,ncol,n,m,maxima-1)%mod)%mod; 
        }
        return dp[row][col][maxima] = ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn, m ,  n,maxMove);
    }
};