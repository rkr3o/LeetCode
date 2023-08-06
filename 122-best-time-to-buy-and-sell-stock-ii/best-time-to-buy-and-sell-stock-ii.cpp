class Solution {
public:
    const int mod = 1e9+7;
    int solve(int i , int buy , vector<int>&prices , vector<vector<int>>&dp)
    {
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int ans = INT_MIN ;
        //buy part

        if(buy==1)
        {
               ans = max(prices[i]+solve(i+1,0,prices,dp) , solve(i+1,1,prices,dp));
        } 
        //sell part
        if(buy==0)
        {
             ans=max(-prices[i]+solve(i+1,1,prices,dp),solve(i+1,0,prices,dp));
        }
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};