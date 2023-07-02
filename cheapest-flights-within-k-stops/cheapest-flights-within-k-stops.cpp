class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>>adj[n];
        for(auto x : flights)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2]; 
            adj[u].push_back({v,wt});       
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9+7);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k)continue;
            for(auto x : adj[node])
            {
                int adjNode = x.first;
                int edgeCost  = x.second;
                if(cost+edgeCost < dist[adjNode] and stops<=k)
                {
                    dist[adjNode] = cost+edgeCost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
         
        if(dist[dst]==1e9+7)return -1;
        return dist[dst];
    }
};