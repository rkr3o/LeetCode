class Solution {
public:
    int dp[300];
    bool solve(int ind , string &s , unordered_set<string>&st)
    {
        if(ind==s.size())
        {
            return true;
        }
        if(dp[ind]!=-1)return dp[ind];
        string req ;
        for(int i = ind ; i < s.size() ; i++)
        {
            req+=s[i];
            if(st.find(req)!=st.end())
            {
                if(solve(i+1,s,st)==true)
                {
                    return dp[ind]=true;
                }
            }
        }
     return dp[ind] =  false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st);
    }
};