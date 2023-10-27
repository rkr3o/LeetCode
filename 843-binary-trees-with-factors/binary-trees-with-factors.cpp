class Solution {
public:
    const int mod = 1e9 + 7;
    long long solve(int target, vector<int>& arr, unordered_set<int>& st, unordered_map<int,long long>&mp) {
        if (mp.find(target) != mp.end()) 
             return mp[target];
        long long ways = 1;  
        for (int i = 0; i < arr.size(); i++) {
            if (target % arr[i] == 0 && st.find(target / arr[i]) != st.end()) {
                ways += solve(arr[i], arr, st, mp) * solve(target / arr[i], arr, st, mp);
                ways %= mod;
            }
        }
        return mp[target] = ways%mod;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        long long cnt = 0;
        int n = arr.size();
        unordered_map<int,long long>mp;
        
        for (int i = 0; i < n; i++) 
        {
            if(mp.find(arr[i])!=mp.end())
            {
                cnt += mp[arr[i]];
                cnt %= mod;
            }
            else
            {
                cnt += solve(arr[i], arr, st, mp);
                cnt %= mod;
            }

        }
        return static_cast<int>(cnt);
    }
};