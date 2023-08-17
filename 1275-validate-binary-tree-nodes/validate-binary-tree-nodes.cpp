class DSU {
    public:
    vector<int> parent, rank, size;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (parent[v] != v)
            parent[v] = find(parent[v]);
        return parent[v];
    }

    void unionByRank(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v])
                swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v])
                rank[u]++;
        }
    }

    void unionBySize(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v])
                swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DSU ds(n);
        vector<int> p(n, -1);

        for (int i = 0; i < n; i++) {
            if (rightChild[i] != -1) {
                int u = ds.find(i);
                if (p[rightChild[i]] != -1) return false;
                int v = ds.find(rightChild[i]);
                p[rightChild[i]] = i;
                if (u == v) return false;
                ds.unionBySize(i, rightChild[i]);
            }
            if (leftChild[i] != -1) {
                int u = ds.find(i);
                int v = ds.find(leftChild[i]);
                if (p[leftChild[i]] != -1) return false;
                p[leftChild[i]] = i;
                if (u == v) return false;
                ds.unionBySize(i, leftChild[i]);
            }
        }

        int cnt = 0;
        int size = 0;

        for (int i = 0; i < n; i++) {
            if (ds.find(i) == i) {
                cnt++;
                size = ds.size[i];
            }
        }

        if (cnt == 1) {
            return size == n;
        }

        return false;
    }
};
