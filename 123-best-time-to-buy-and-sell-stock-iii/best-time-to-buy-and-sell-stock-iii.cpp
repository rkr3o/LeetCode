class Solution {
public:
    #define ll long long
    int solve(int i , int buy , int cap , vector<int>&prices , vector<vector<vector<int>>>&dp)
    {
        if(i==prices.size() || cap==0)return 0 ;
        
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        ll maxima = 0 ;
     
        if(buy==1)
        {
            maxima = max(prices[i]+solve(i+1,0,cap-1,prices,dp) ,solve(i+1,1,cap,prices,dp)); 
        }
        else
        {
           maxima = max(-prices[i]+solve(i+1,1,cap,prices,dp) ,solve(i+1,0,cap,prices,dp));
        }
        return dp[i][buy][cap]=maxima;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,0,2,prices,dp);
    }
};