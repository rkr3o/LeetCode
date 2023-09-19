class Solution {
public:
    bool solve(int n,int m,string& s,string& p,vector<vector<int>>&dp){
        // cout<<n<<" "<<m<<'\n';
        if(n<0 && m<0) return 1;
        if(n<0){
            while(m>=0){
                if(p[m]!='*') return 0;
                m-=2; // _a* -> m at * so it will delete a as well so m-=2
            }
            return 1;
        }
        if(m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(p[m]=='.' || s[n]==p[m]) return dp[n][m]=solve(n-1,m-1,s,p,dp);
        if(p[m]=='*'){
            dp[n][m]=solve(n,m-2,s,p,dp); // 0 occurence of last characters
            if((p[m-1]=='.' || p[m-1]==s[n])) dp[n][m]|=solve(n-1,m,s,p,dp); // take occurence of last character 
            return dp[n][m];
        }
        return dp[n][m]=0;
    }
    
    // here c* => "cccccccc" (* means 0/multiple occurence of prev char)
    bool isMatch(string s, string p){
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};
