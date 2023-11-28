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
private:
    void sieve(int maxNum, vector<vector<int>>& factors) {
        for (int i = 2; i <= maxNum; i++) {
            if (factors[i].empty()) {  // i is a prime number
                for (int j = i; j <= maxNum; j += i) {
                    factors[j].push_back(i);
                }
            }
        }
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(begin(nums), end(nums));
        int n = nums.size();
        DSU ds(maxNum);

        // Prime factorization using Sieve of Eratosthenes
        vector<vector<int>> factors(maxNum + 1);
        sieve(maxNum, factors);

        for (int i = 0; i < n; i++) {
            for (int factor : factors[nums[i]]) {
                ds.unionByRank(nums[i], factor);
            }
        }

        unordered_map<int, int> mp;
        for (auto& x : nums) {
            mp[ds.find(x)]++;
        }

        int len = 0;
        for (const auto& [key, value] : mp) {
            len = max(len, value);
        }

        return len;
    }
};