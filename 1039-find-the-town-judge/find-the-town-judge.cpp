class Solution {
public:
    int findJudge(int n, vector<vector<int>>& adj) 
    {
         vector<int>person(n+1,0);
         
         for(auto x: adj)
         {
             int u = x[0];
             int v = x[1];
             person[u]--;
             person[v]++;
         }    
         
         for(int i = 1 ;i<=n ; i++)
         {
             if(person[i]==n-1)
               return i ;
         }

      return -1;
    }
};