class Solution {
public:
    bool dfs(int src , vector<int>&vis , vector<int>&pathVis , vector<int>prerequisites[])
    {
        vis[src]=1;
        pathVis[src]=1;
        for(auto x : prerequisites[src])
        {
             if(!vis[x])
             {
                 if(dfs(x,vis,pathVis,prerequisites)==true)return true;
             }
             else if(pathVis[x])
             {
                 return true;
             }
        }
        pathVis[src]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int>adj[n];
        for(auto x: prerequisites)
        {
            adj[x[0]].push_back(x[1]);
        }
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);

        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathVis ,adj)==true)
                {
                    return false;
                }
            }
        }    
        return true;
    }
};