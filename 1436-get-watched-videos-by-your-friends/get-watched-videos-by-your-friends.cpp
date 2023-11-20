class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        queue<pair<int,int>>q;
        vector<int>vis(n,0);
        q.push({id,0});
        vis[id]=1;
        vector<int>ans;
        while(!q.empty())
        {
            int id = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(lvl==level)
            {
                ans.push_back(id);
            }
            for(auto x : friends[id])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push({x,lvl+1});
                }
            }
        }
        unordered_map<string,int>mp;
        for(auto x : ans)
        {
            for(auto y : watchedVideos[x])
            {
                mp[y]++;
            }
        }
        vector<pair<int,string>>res;
        for(auto &[x,y] : mp)res.push_back({y,x});
        sort(begin(res),end(res));
        vector<string>minima;
        for(auto &[x,y] : res)minima.push_back(y);
        return minima;
    }
};