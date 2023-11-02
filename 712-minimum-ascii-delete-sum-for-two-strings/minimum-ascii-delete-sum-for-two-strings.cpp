class Solution {
public:
    int dp[1000][1000];
    int solve(int i , int j , string &s , string &t)
    {
        if(i<0 || j<0)return 0 ;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j] = s[i]+solve(i-1,j-1,s,t);
        }
        else
        {
            return dp[i][j]= max(solve(i-1,j,s,t),solve(i,j-1,s,t));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int sum = 0;    
        memset(dp,-1,sizeof(dp));
        for(auto x : s1)sum+=x;
        for(auto x : s2)sum+=x;
        int lcsSum = solve(n-1,m-1,s1,s2);
        return sum-2*lcsSum;
    }
};