class Solution {
public:
    int dp[1001][1001];
    int solve(int steps , int cur , int add , int target)
    {
         if(steps>target || cur>target)return INT_MAX;
         if(cur==target)
         {
             return steps;
         }
         if(dp[steps][cur]!=-1)return dp[steps][cur];
         int paste = solve(steps+1,cur+add,add,target);
         int copyPaste = solve(steps+2 , 2*cur , cur , target);
         return dp[steps][cur] = min(paste,copyPaste);
    }
    int minSteps(int n) {
        if(n==1)return 0;
        memset(dp,-1,sizeof(dp));
        return solve(1,1,1,n);
    }
};