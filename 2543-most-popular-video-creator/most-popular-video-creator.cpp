class Solution {
public:
using ll = long long int ;
    vector<vector<string>> mostPopularCreator(vector<string>& v, vector<string>& id, vector<int>& views) {
        map<string, map<string, int>> mp;
        unordered_map<string, ll> mp2;
        int n = v.size(); 
        for (int i = 0; i < n; i++) {
            mp[v[i]][id[i]] = views[i];
            mp2[v[i]] += views[i];
        }
        ll maxima = INT_MIN;
        for (auto &[x, y] : mp2) {
            maxima = max(maxima, (ll)y);
        }
        vector<vector<string>> ans;
        for (auto x : mp) 
        {
            string owner = x.first;
            if (mp2[owner] == maxima) 
            {
                int maxima = INT_MIN;
                string temp = "";
                for (auto y : x.second) 
                {
                    string id = y.first;  
                    ll value = y.second;  
                    if (value > maxima) {
                        maxima = value;
                        temp = id;
                    } else if (value == maxima) {
                        continue;
                    }
                }
                ans.push_back({owner, temp});
            }
        }
        return ans;
    }
};
