class Solution {
public:
    bool dfs(int src ,vector<int>&vis,vector<int>&pathVis, vector<int>&check , vector<int>adj[])
    {
        vis[src]=1;
        pathVis[src]=1;
        check[src]=0;
        for(auto x: adj[src])
        {
            if(!vis[x])
            {
                if(dfs(x,vis,pathVis,check,adj)==true)
                {
                    check[src]=0;
                    return true;
                }
            }
            else if(pathVis[x])
            {
                check[src]=0;
                return true;
            }
        }
        pathVis[src]=0;
        check[src]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int>adj[n];
        for(int i = 0 ; i < n; i++)
        {
            for(auto x : graph[i])
            {
                adj[i].push_back(x);
            }
        }
        vector<int>check(n,0);
        vector<int>path(n,0);
        vector<int>vis(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,path,check,adj);            
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i++)
        {
            if(check[i]==1)ans.push_back(i);
        }
        return ans;
    }
};