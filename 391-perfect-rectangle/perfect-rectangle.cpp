class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mp;
        for(auto x : rectangles)
        {
            mp[{x[0],x[1]}]++;
            mp[{x[0],x[3]}]--;
            mp[{x[2],x[1]}]--;
            mp[{x[2],x[3]}]++;
        }
        int cnt = 0 ;
        for(auto x : mp)
        {
            if(x.second!=0)
            {
                if(abs(x.second) != 1)return false;
                cnt++;
            }
        }
        return cnt==4;
    }
};