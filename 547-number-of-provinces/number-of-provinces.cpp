class DSU
{
public :
    vector<int>rank , parent , size;
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0 ; i <= n ; i++)
        {
            parent[i] = i;
        }
    }

    // path compression
    int find(int v)
    {
        if (v == parent[v])return v;
        return parent[v] = find(parent[v]);
    }

    void unionByRank(int u , int v )
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
         int n = isConnected.size();
         DSU ds(n);
         int cnt =0 ;
         for(int i = 0 ; i <n ;i++)
         {
             for(int j = 0 ; j < n ; j++)
             {
                 if(isConnected[i][j]==1)
                 {                    
                         ds.unionByRank(i,j);    
                 }
             }
         }
         
         for(int i = 0 ; i < n ;i++)
         {
             if(ds.parent[i]==i)cnt++;
         }

         return cnt;
    }
};