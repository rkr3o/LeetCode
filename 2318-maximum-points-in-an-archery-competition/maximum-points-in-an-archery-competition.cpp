class Solution {
public:
using ll = long long int;
    ll solve(int ind , int t , vector<int>&bob , vector<vector<int>>&dp)
    {
        if(ind<0 || t<0)return 0;
        if(t==0)return 0;
        if(dp[ind][t]!=-1)return dp[ind][t];
        ll notPick = solve(ind-1,t,bob,dp);
        ll pick = INT_MIN;
        if(bob[ind] <= t)
        {
            pick = ind+solve(ind-1,t-bob[ind],bob,dp);
        }
        return dp[ind][t] = max(pick,notPick);
    }
    vector<int> maximumBobPoints(int arrows, vector<int>& aliceArrows) {
        int n =aliceArrows.size(); 
        vector<int>bob;
        vector<vector<int>>dp(n,vector<int>(arrows+1,-1));
        vector<int>ans(12,0);
        for(auto x :aliceArrows)
        {
            bob.push_back(x+1);
        }
        solve(n-1,arrows,bob,dp);
        for(int i = n-1 ; i > 0 and arrows > 0 ; i--)
        {
            if(arrows>=bob[i] and dp[i][arrows]>dp[i-1][arrows])
            {
                ans[i]=bob[i];
                arrows-=bob[i];
            }
        }
         if(arrows>0)ans[0] = arrows;
        
        return ans;
    }
};