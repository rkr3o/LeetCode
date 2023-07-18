class Solution {
public:
   int dp[1000];
    int catalan(int n)
    {
        if(n<=1)return 1 ;
        if(dp[n]!=-1)return dp[n];
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            ans+=catalan(i)*catalan(n-i-1);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
      memset(dp,-1,sizeof(dp));
           return catalan(n);
    }
};