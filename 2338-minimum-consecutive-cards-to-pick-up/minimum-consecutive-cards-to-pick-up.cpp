class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        int minima = INT_MAX;
        int cnt = 0 ;
        int n = v.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++)
        {
            if(mp.find(v[i])!=mp.end())
            {
                minima = min(minima,i-mp[v[i]]+1);
            }
            mp[v[i]]=i;
        }
        if(minima==INT_MAX)return -1;
        return minima;
    }
};