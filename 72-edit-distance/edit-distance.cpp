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
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i = 0 ; i <=n ; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0 ; j <=m ; j++)
        {
            dp[0][j] = j;
        }
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j =1 ; j<=m ; j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                 else dp[i][j]=min({1+dp[i][j-1],1+dp[i-1][j] , 1+dp[i-1][j-1]});
            }
        }
        return dp[n][m]; 
    }
};