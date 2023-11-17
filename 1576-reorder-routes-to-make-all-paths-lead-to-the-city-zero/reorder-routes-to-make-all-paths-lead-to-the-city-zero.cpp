class Solution {
public:
    int minima = 0 ;
    void solve(int src ,vector<int>&vis , vector<pair<int,int>>adj[])
    {
        vis[src]=1;
        for(auto x : adj[src])
        {
            if(!vis[x.first])
            {
                if(x.second)
                  minima++;
                solve(x.first,vis,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>adj[n];
        for(auto x : connections)
        {
            int u = x[0];
            int v = x[1];
            adj[u].push_back({v,1});
            //virtual edge
            adj[v].push_back({u,0});
        }
        vector<int>vis(n,0);
        solve(0,vis,adj);
        return minima;
    }
};