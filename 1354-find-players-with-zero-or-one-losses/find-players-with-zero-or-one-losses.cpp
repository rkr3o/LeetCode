class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        set<int>arr;
        map<int,int>out;
        for(auto x : matches)
        {
            int u = x[0];
            int v = x[1];
            out[v]++;
            arr.insert(u);
            arr.insert(v);
        }
        int cnt = 1;
        vector<int>t2,t1;
        for(auto x : out)
        {
            if(x.second==1)
                t2.push_back(x.first);
        }
        for(auto x : arr){
            if(out.find(x)==out.end())
                t1.push_back(x);
        }
        ans.push_back(t1);
        ans.push_back(t2);
        return ans;
    }
};