class Solution {
     const int N = 1e5+10;
    const int INF = 1e9+10;
    int dijkastra(vector<pair<int,int>>adj[] , int n , int src)
    {
          queue<pair<int,int>>pq;
          pq.push({0,src});
          vector<int>dist(N,INF);
          dist[src]=0;
          while(!pq.empty())
          {
              int minTime = pq.front().first;
              int node = pq.front().second;
              pq.pop();
              for(auto x : adj[node])
              {
                  int adjNode = x.first;
                  int edgeTime = x.second;

                  if(minTime+edgeTime < dist[adjNode])
                  {
                      dist[adjNode]=minTime+edgeTime;
                      pq.push({dist[adjNode],adjNode});
                  }
              }
          }
          int ans = 0 ;
          for(int i = 1 ; i <= n ; i++)
          {
              if(dist[i]==INF)return -1;
              else ans = max(dist[i],ans);
          }
return ans;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>>adj[N];
        for(auto x : times)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }

        return dijkastra(adj,n,k);
    }
};