class Solution {
public:
    int getTime(int src , int par , int bob , vector<int>& time , vector<int> adj[]) {
        if (src == bob) return time[src] = 0;
        for (auto x : adj[src]) {
            if (x == par) continue;
            int t = getTime(x, src, bob, time, adj);
            if (t != -1) return time[src] = 1 + t;
        }
        return -1;
    }
    
    void dfs(int alice , int par , vector<int>& time , vector<int>& amt , vector<int> adj[] , int curSum , int curTime , int &ans) {
        if (curTime < time[alice]) curSum += amt[alice];
        else if (curTime == time[alice]) curSum += amt[alice] / 2;

        if (adj[alice].size() == 1 && alice) ans = max(ans, curSum);

        for (auto x : adj[alice]) {
            if (x == par) continue;
            dfs(x, alice, time, amt, adj, curSum, curTime + 1, ans);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> adj[n+1];
        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> time(n+1, 1e6);
        getTime(0, -1, bob, time, adj);
        int ans = -2e9;
        dfs(0, -1, time, amount, adj, 0, 0, ans);
        return ans;
    }
};
