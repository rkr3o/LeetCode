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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        map<string,int>mp;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j < accounts[i].size() ; j++)
            {
                string mail = accounts[i][j];
                if(mp.find(accounts[i][j])==mp.end())
                {
                      mp[mail]=i;
                }
                else
                {
                      ds.UnionByRank(i,mp[mail]);
                }
            }
        }
        //now merge the mail
        vector<string>merge[n];
        for(auto it : mp)
        {
            string mail = it.first;
            int node = ds.find(it.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i = 0;  i < n ; i++)
        {
            if(merge[i].size()==0)continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto x : merge[i])
            {
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};