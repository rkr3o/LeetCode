class Solution {

   int dp[1005][1005];
   bool Solve(string& s,string& p,int i,int j)
   {
       if(j==p.length())
            return i==s.length();
       if(dp[i][j]!=-1)
            return dp[i][j];
       bool first=(i<s.length() && (s[i]==p[j] || p[j]=='.'));
       if(j+1<p.length() && p[j+1]=='*')
       {
            return dp[i][j]= Solve(s,p,i,j+2) || (first && Solve(s,p,i+1,j));
       }
       else
           return dp[i][j]=(first && Solve(s,p,i+1,j+1));
   }
public:
    bool isMatch(string s, string p) 
    {
         memset(dp,-1,sizeof(dp));
         return Solve(s,p,0,0);
    }
};