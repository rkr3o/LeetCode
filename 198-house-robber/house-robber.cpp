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
    int rob(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int n = v.size();
        if(n==0)return 0 ;
        int prev=v[0];
		int prev2 = 0;
		for (int i = 1; i < n; i++) {
			int pick = v[i];
            if(i>1)
            {
                pick+=prev2;
            }
			int notPick = prev;
            int cur = max(notPick, pick);
            prev2 = prev;
            prev=cur;
		}
		return prev;
    }
};