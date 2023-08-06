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
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int i = n-1 ; i >=0 ; i--)
        {
            for(int buy = 0 ; buy<=1 ; buy++)
            {
                int profit = 0 ;
               if(buy)
                {
                    profit = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }
                else 
                {
                    profit = max(prices[i]+dp[i+1][1], dp[i+1][0]);
                }

                dp[i][buy]=profit;
            }
        } 
        return dp[0][1];

    }
};