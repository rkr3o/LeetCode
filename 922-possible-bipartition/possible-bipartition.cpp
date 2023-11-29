class DSU {
public:
    vector<int> rank, parent, size;

    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void unionByRank(int u, int v) {
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DSU dsu(2*n);

        for (const auto& dislike : dislikes) {
            int u = dislike[0]-1;
            int v = dislike[1]-1;

            // If both u and v are in the same group, return false
            if (dsu.find(u) == dsu.find(v))
                return false;

            // Union the opposite groups
            dsu.unionByRank(u, v + n);
            dsu.unionByRank(v, u + n);
        }

        // Check if all elements are in separate groups
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == dsu.find(i + n))
                return false;
        }

        return true;
    }
};
