class Solution {
    int timer = 1;
    void solve(int src , int parent,vector<int>adj[] , vector<int>&low , vector<int>&inTime , vector<vector<int>>&bridges ,vector<int>&vis)
    {
          //visiting the node 
          vis[src]=1;
          low[src]=inTime[src]=timer ;
          timer++;
          for(auto x : adj[src])
          {
              if(x==parent)continue;
              if(vis[x]==0)
              {
                    solve(x,src,adj,low,inTime,bridges,vis);
                    low[src]=min(low[src],low[x]);
                    //check for bridge 
                    if(low[x] > inTime[src])
                    {
                        bridges.push_back({x,src});
                    }
              }
              else
              {
                    low[src]=min(low[src],low[x]);
              }
          }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
            vector<int>adj[n];
            for(auto x :connections)
            {
                int u = x[0];
                int v = x[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<int>low(n);
            vector<int>inTime(n);
            vector<int>vis(n,0);
            vector<vector<int>>bridges;
            solve(0,-1,adj,low,inTime,bridges,vis);
            return bridges;
    }
};