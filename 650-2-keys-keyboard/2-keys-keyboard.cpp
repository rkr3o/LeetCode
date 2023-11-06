class Solution {
public:
    int dp[1001][1001];
    int solve( int cur , int add , int target)
    {
         if(cur>target)
           return 1e9;
         if(cur==target)
         {
             return 0;
         }
         if(dp[cur][add]!=-1)return dp[cur][add];
         int paste = 1+solve(cur+add,add,target);
         int copyPaste = 2+solve(2*cur , cur , target);
         return dp[cur][add] = min(paste,copyPaste);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        memset(dp,-1,sizeof(dp));
        return solve(1,1,n)+1;
    }
};