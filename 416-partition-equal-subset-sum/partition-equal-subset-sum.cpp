class Solution {
    bool solve(int n , int target ,vector<int>&v,vector<vector<int>>&dp)
{
    if(target==0)return true;
    if(n==0)
        return (v[0]==target);
    
    if(dp[n][target]!=-1)
    {
        return dp[n][target];

    } 
    bool take = false;
    if(v[n]<=target)
    {
        take = solve(n-1,target-v[n],v,dp);    
    }
    bool notPick = solve(n-1,target,v,dp);
    
    return dp[n][target]= take|notPick;
}
public:
    bool canPartition(vector<int>& v) 
    {
        int n = v.size();
        long long int k = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        k+=v[i];
    }
    if(k & 1)return false;
    int target = k/2;
    
	vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solve(n-1,target,v,dp);
    }
};