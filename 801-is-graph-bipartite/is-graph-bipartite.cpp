class Solution {
public:
    bool dfs(int src , vector<vector<int>>&adj , int col , vector<int>&vis , vector<int>&color)
    {
           color[src]=col;
           for(auto x:  adj[src])
           {
               if(color[x]==-1)
               {
                   if(dfs(x,adj,col^1,vis,color)==true)
                   {
                       return true;
                   }
               }
               else if(color[x]==col)
               {
                   return true;
               }
           }
           return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        for(int i = 0 ; i < n ; i++)
        {
              if(col[i]==-1)
              {
                  if(dfs(i,graph,0,vis,col)==true)
                  {
                     return false;
                  }
              }
        }
        return true;
    }
};