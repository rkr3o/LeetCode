class Solution {
public:
    int crossTime(int cur , int bob,  int prev , vector<int>adj[] , vector<int>&time)
    {
        if(cur==bob)return time[cur]=0;
        for(auto x : adj[cur])
        {
            //overcome from cycle
            if(x==prev)continue;
            int timeReach = crossTime(x,bob,cur,adj,time);
            if(timeReach!=-1) return time[cur]=1+timeReach;
        }
        return -1;
    }
    void dfs(int alice , int prev , vector<int>&amount , vector<int>&time , vector<int>adj[] , int curSum , int curTime , int &ans)
    {
        if(curTime < time[alice])curSum+=amount[alice];
        else if(curTime==time[alice])curSum+=amount[alice]/2;
        if(adj[alice].size()==1 and alice) ans = max(ans,curSum);
        for(auto x : adj[alice])
        {
            if(x==prev)continue;
            dfs(x,alice,amount,time,adj,curSum,curTime+1,ans);
        }
        return ;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
         int n = edges.size();
         vector<int>adj[n+1];
         for(auto x: edges)
         {
             int u = x[0];
             int v = x[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
         vector<int>time(n+1,1e6);
         crossTime(0,bob,-1,adj,time);
         int ans = -2e9;
         dfs(0,-1,amount,time,adj,0,0,ans);
         return ans;
    }
};