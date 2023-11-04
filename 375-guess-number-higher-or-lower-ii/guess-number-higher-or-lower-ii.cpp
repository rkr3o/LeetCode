class Solution {
public:
    int dp[201][201];
    int solve(int left, int right)
    {
        if(left>=right)return 0 ;
        if(dp[left][right]!=-1)return dp[left][right];
        int ans = INT_MAX;
        for(int i = left ; i<=right ; i++)
        {
            ans = min(ans,i+max(solve(left,i-1),solve(i+1,right)));
        }
        return  dp[left][right] = ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};