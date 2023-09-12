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
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i = 1 ; i < n ; i++)
        {
            int notPick = dp[i-1];
            int pick = nums[i];
            if(i>1)pick+=dp[i-2];
            dp[i] = max(pick,notPick);
        }
        return dp[n-1];
    }
};