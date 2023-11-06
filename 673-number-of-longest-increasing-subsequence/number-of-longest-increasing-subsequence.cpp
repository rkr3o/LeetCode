class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);
        int maxima =1 ;
        for(int i = 1 ; i < n ; i++)
        {
            for(int prev = 0 ; prev<i ; prev++)
            {
                if(nums[i]>nums[prev] and 1+dp[prev] > dp[i])
                {
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }
                else if(nums[i]>nums[prev] and 1+dp[prev]==dp[i])
                {
                    cnt[i]+=cnt[prev];
                }
            }
            maxima = max(maxima,dp[i]);
        }
         int nos=0 ;
        for(int i = 0 ;i<n ; i++)
        {
            if(dp[i]==maxima)nos+=cnt[i];
        }

        return nos;
    }
};