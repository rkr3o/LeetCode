class Solution {
public:
    int dp[100];
    int solve(int ind , vector<int>&nums)
    {
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int notPick = solve(ind-1,nums);
        int pick = nums[ind]+solve(ind-2,nums);
        return dp[ind] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        if(n==0)return 0 ;
        return solve(n-1,nums);
    }
};