class DSU
{
public:
    vector<int> parent, size, rank;

    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int v)
    {
        if (parent[v] == v)
        {
            return v;
        }
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
    bool equationsPossible(vector<string> &equations)
    {
        DSU dsu(26); 
        // Union operations for equations with '==' relation
        for (const string &equation : equations)
        {
            if (equation[1] == '=')
            {
                int u = equation[0] - 'a';
                int v = equation[3] - 'a';
                dsu.UnionBySize(u, v);
            }
        }

        // Check if variables in equations with '!=' relation are in the same connected component
        for (const string &equation : equations)
        {
            if (equation[1] == '!')
            {
                int u = equation[0] - 'a';
                int v = equation[3] - 'a';
                if (dsu.find(u) == dsu.find(v))
                {
                    return false; // Contradiction found
                }
            }
        }

        return true; // No contradiction found, equations are satisfiable
    }
};