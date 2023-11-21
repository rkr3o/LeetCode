class DSU
{
private:
    vector<int> parent, rank, size;

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
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void UnionBySize(int u, int v)
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

    void UnionByRank(int u, int v)
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

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DSU ds(n);
        int component = 0;
        int extra = 0;
        for (auto x : connections)
        {
            if (ds.find(x[0]) != ds.find(x[1]))
            {
                ds.UnionByRank(x[0], x[1]);  // Fix: Correct the index to x[1]
            }
            else
            {
                extra++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ds.find(i) == i)
                component++;
        }
        if (extra >= component - 1)
            return component - 1;
        return -1;
    }
};
