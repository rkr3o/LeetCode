class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //create adjancenct list : we have to find pair , whose combination of node conneted make is maximum
        unordered_map<int,unordered_set<int>>adj;
        for(auto x: roads)
        {
            adj[x[0]].insert(x[1]);
             adj[x[1]].insert(x[0]);
        }
        int maxima = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1; j < n ; j++)
            {
                 int rank =  adj[i].size()+adj[j].size();
                 if(adj[i].find(j)!=adj[i].end())
                    rank--;
                 maxima=max(maxima,rank);
            }
        }
        return maxima;
    }
};