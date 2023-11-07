class Solution {
public:
      bool solve(int ind , int target , vector<int>&v , vector<vector<int>>&dp)
    {
         if(target==0)return dp[ind][target]=true;
         if(ind==0)return dp[ind][target] = v[0] == target;

         if(dp[ind][target]!=-1)return dp[ind][target];   
              
         bool notpick = solve(ind-1,target,v,dp);  
         bool pick = false;
         if(v[ind]<=target)
         {
             pick = solve(ind-1,target-v[ind],v,dp);
         }
        

         return dp[ind][target] = pick ||notpick;
   }
    int lastStoneWeightII(vector<int>& v) {
       
        int totSum = 0 ;
        int n = v.size();
        for(int i = 0 ; i < n ; i++)
        {
            totSum+=v[i];
        }
        vector<vector<int>>dp(n,vector<int>(totSum+1,-1));

        for(int i = 0 ;i <= totSum ; i++)
        {
            bool dummy= solve(n-1,i,v,dp);
        }

        int mini = 1e9;
        for(int i = 0 ; i <=totSum/2 ; i++)
        {
            if(dp[n-1][i]==true)
            {
                int diff = abs(i-(totSum-i));
                mini = min(diff,mini);
            }
        }
       return mini;
    }
};