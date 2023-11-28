class DSU {
public:
    vector<int> parent, size, rank;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    void UnionBySize(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
        }
    }

    void UnionByRank(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v]) {
                rank[u]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n = edges.size();
        DSU ds(n);
        for(auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            if(ds.find(u)!=ds.find(v))
            {
                ds.UnionByRank(u,v);
            }
            else
            {
                ans.push_back(u);
                ans.push_back(v);
            }
        }
        return ans;
    }
};