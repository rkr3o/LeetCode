class Solution {
public:
    long long solve(int ind , int t , vector<long long>&arr , vector<vector<int>>&dp)
    {
        if(ind>=arr.size() || t<0)
          return INT_MAX;
        if(t==0)return 0;
        if(dp[ind][t]!=-1)return dp[ind][t];
        long long  notPick = solve(ind+1,t,arr,dp);
        long long pick = INT_MAX;
        if(arr[ind]<=t)
        {
             pick = 1+solve(ind,t-arr[ind],arr,dp);
        }
        return dp[ind][t]=min(pick,notPick);
    }
    int numSquares(int t) 
    {
        vector<long long>arr;
        for (int i = 1; i <= 100; ++i)
        {
            arr.push_back(i*i);
        }
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return solve(0,t,arr,dp);
    }
};