class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int cnt = 0 ;
        int n = tasks.size();
        unordered_map<int,int>mp;
        for(auto x : tasks) 
            mp[x]++;
        bool k = 0 ;
        for(auto &x : mp) 
        {
             if(x.second==1)
             {
                 k=true;
                 break;
             }
             cnt+=ceil(x.second/3.0);
        }
        if(k)return -1;
        return cnt;
    }
};
