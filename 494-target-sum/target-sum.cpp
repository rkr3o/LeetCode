
#define ll long long int 
class Solution {

    int solve(int n , int t , vector<int>&v , vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(v[0]==0 and t == 0)
            return 2 ;
            if(t==0 || t==v[0]) return 1 ;
            return 0 ;
        }
        if(dp[n][t]!=-1)return dp[n][t];
        int pick = 0 ;
        if(v[n]<=t)
        {
            pick = solve(n-1,t-v[n],v,dp);
        }
        int notpick = solve(n-1,t,v,dp);

        return dp[n][t] = pick+notpick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target)
     {
        ll sum = 0;
        for(auto &x : nums)sum+=x;
        int n = nums.size();
        if((sum-target)&1)return 0 ;
        if(sum-target<0)return 0 ;
        int s1 = (sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(s1+1,-1));

        return solve(n-1 , s1 ,  nums , dp);
    }
};