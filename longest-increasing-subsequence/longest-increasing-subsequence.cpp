class Solution {
public:
    int solve(int i , int prev , int n , vector<int>&nums, vector<vector<int>>&dp)
    {
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int len = solve(i+1,prev,n,nums,dp);
        int pick = INT_MIN;
        if(prev==-1 || nums[i]>nums[prev])
        {
            len = max(len,1+solve(i+1,i,n,nums,dp));
        } 
        return dp[i][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       if(n==0)return 0;
       if(n==1)return 1;
       vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return solve(0,-1,n,nums,dp);
    }
};