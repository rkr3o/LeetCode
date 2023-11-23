class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        if(nums.empty()) return {};
        vector<int> ans;
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        int i = 0 ;
        while(mp.find(i)!=mp.end())
        {
            vector<int>p;
            for(auto x : mp[i])
            {
                p.push_back(x);
            }
            i++;
            reverse(p.begin(), p.end());
            ans.insert(ans.end(), p.begin(), p.end());
        }
        return ans;
    }
};
