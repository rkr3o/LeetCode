class Solution {
public:
    int dp[500][500];
    int solve(int i , int j , string &s , string &t)
    {
        if(i<0)return j+1; // string is exhausted
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j] = solve(i-1,j-1,s,t);
        }
        else
        {
            return dp[i][j] = 1+min({solve(i-1,j,s,t),solve(i,j-1,s,t),solve(i-1,j-1,s,t)});
        }
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1,s,t);
    }
};