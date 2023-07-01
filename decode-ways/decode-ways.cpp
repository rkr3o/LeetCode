 class Solution
 {
     public:
         int solve(const string &s, int idx , vector<int>&dp)
         {
             if (idx == s.size())return 1;	 
             if (s[idx] == '0')return 0;	
             if(dp[idx]!=-1)return dp[idx];
             int cnt = 0;	 
             if(s[idx]!='0')
             {
                 cnt += solve(s, idx + 1,dp);	
             } 
             if (idx + 1 < s.size())
             {
                 int twoDigits = (s[idx] - '0') *10 + (s[idx + 1] - '0');
                 if (twoDigits >= 10 && twoDigits <= 26)
                 cnt += solve(s, idx + 2,dp); 
             }
             return dp[idx] = cnt;
         }
     int numDecodings(string s)
     {  
         int n = s.size();
         vector<int>dp(n,-1);
         return solve(s, 0 ,dp);
     }
 };