class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int>ans;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto x : nums)mp[x]++;
        for(auto &[x,y] : mp)
        {
            if(y==1)ans.push_back(x);
        }
        return ans;
    }
};