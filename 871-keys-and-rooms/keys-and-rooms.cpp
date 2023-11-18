class Solution {
public:
void dfs(int src , vector<int>&vis , vector<int>adj[])
{
    vis[src]=1;
    for(auto x: adj[src])
    {
        if(!vis[x])
        {
            dfs(x,vis,adj);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>adj[n];
        for(int i = 0 ; i < n ; i++)
        {
            for(auto x : rooms[i])
            {
                adj[i].push_back(x);
                //adj[x].push_back(i);
            }
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i  = 0 ; i < n ;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt==1;
    }
};