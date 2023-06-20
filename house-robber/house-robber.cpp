class Solution {
public:
    int solve(int n , vector<int>&nums , vector<int>&dp)
    {
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int notPick =  solve(n-1,nums,dp);
        int pick = INT_MIN;
        pick = nums[n]+solve(n-2,nums,dp); 
        return dp[n] =  max(pick,notPick);
    }
    int rob(vector<int>& v) 
    { 
        int n = v.size();
        if(n==0)return 0 ;
        vector<int>dp(n,-1);
        return solve(n-1,v,dp);
    }
};