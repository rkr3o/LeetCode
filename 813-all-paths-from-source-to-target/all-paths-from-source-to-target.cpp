class Solution {
public:
    int target;
    vector<vector<int>> ans;
    void solve(int src , vector<int>path , vector<int>adj[])
    {
        path.push_back(src);
        if(src==target)
        {
            ans.push_back(path);
            return;
        }
        for(auto x : adj[src])
        {
            solve(x,path,adj);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
       
        int n = graph.size();
        vector<int>adj[n];
        target=n-1;
        vector<int>path;
        for (int i = 0; i < n; i++) 
        {
            for (auto vertex : graph[i]) 
            {
                adj[i].push_back(vertex);
            }
         }
         solve(0,path,adj);
         return ans;
    }
};