class Solution {
public:
    int dp[601][101][101];
    int solve(int ind , int n , int m , vector<string>&ans)
    {
        if(ind>=ans.size())return 0;
        if(dp[ind][n][m]!=-1)return dp[ind][n][m];
        int zeros = count(begin(ans[ind]),end(ans[ind]),'0');
        int ones = ans[ind].size()-zeros;
        int notPick = solve(ind+1,n,m,ans);
        int pick = INT_MIN;
        if(zeros<=n and ones<=m)
        {
            pick = 1+solve(ind+1,n-zeros,m-ones,ans);
        }
        return dp[ind][n][m]= max(pick,notPick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n,strs);
    }
};