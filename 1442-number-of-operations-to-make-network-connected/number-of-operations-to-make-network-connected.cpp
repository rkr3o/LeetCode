class Solution {
public:
    class DSU
{
private:
    vector<int>parent , rank , size;
public:
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }
 
    int find(int v)
    {
        if (v == parent[v])return v;
        return parent[v] = find(parent[v]);
    }
 
    void UnionBySize(int u , int v )
    {
        u = find(u);
        v = find(v);
 
        if (u != v)
        {
            if (size[u] < size[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
        }
    }
    void UnionByRank(int u , int v )
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extra = 0 ;
        int component =  0;
        for(auto x : connections)
        {
            int u = x[0];
            int v = x[1];
            if(ds.find(u)!=ds.find(v))
            {
                ds.UnionByRank(u,v);
            }
            else
            {
                extra++;
            }
        }
        for(int i = 0; i < n ; i++)
        {
            if(ds.find(i)==i)component++;
        }
        if(extra>=component-1)return component-1;
        return -1;
    }
};