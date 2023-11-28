class DSU {
public:
    vector<int> size, parent;

    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void unionBySize(int u, int v) {
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
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(begin(nums), end(nums));
        int n = nums.size();
        DSU ds(maxNum);

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 2; j <= sqrt(nums[i]); j++) {
                if(nums[i] % j == 0) {
                    ds.unionBySize(nums[i], j);
                    ds.unionBySize(nums[i], nums[i] / j);
                }
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
