class Solution {
public:
    const int mod = 1e9 + 7;
    using ll = long long int;

    ll solve(int ind, int n, int delay, int forget , vector<int>&dp) {
        if (ind > n) {
            return 0;  // Base case: No one knows the secret if the day exceeds n.
        }
        if(dp[ind]!=-1)return dp[ind];
        ll cnt = 1;
        if (ind + forget <= n) {
            cnt--;
        }
        for (int i = ind + delay; i < min(n + 1, ind + forget); i++) {
            cnt += solve(i, n, delay, forget,dp);
            cnt%=mod;
        }
        return dp[ind]=cnt%mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,-1);
        return solve(1, n, delay, forget,dp);
    }
};
