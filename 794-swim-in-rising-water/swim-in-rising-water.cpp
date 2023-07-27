class Solution {
public:
 
class DSU {
public:
    vector<int> parent, size, rank;
    
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) return v;
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

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int, int>> positions;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            positions.emplace_back(grid[i][j], i * n + j);
        }
    }

    sort(positions.begin(), positions.end());

    DSU uf(n * n);
    int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minTime = 0;

    for (const auto& pos : positions) {
        int height = pos.first;
        int index = pos.second;

        int row = index / n;
        int col = index % n;

        minTime = max(minTime, height);

        for (const auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            int newIndex = newRow * n + newCol;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] <= height) {
                uf.UnionBySize(index, newIndex);
            }
        }

        if (uf.find(0) == uf.find(n * n - 1)) {
            return minTime;
        }
    }

    return -1; // Unable to reach the bottom right square.
}

};