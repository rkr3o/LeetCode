class Solution {
public:
    void solve(int ind , vector<int>&v , vector<int>ds , vector<vector<int>>&ans , int target)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }   if(ind<0)return ;
        solve(ind-1,v,ds,ans,target);
        if(v[ind]<=target)
        {
            ds.push_back(v[ind]);
            solve(ind,v,ds,ans,target-v[ind]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(n-1,candidates,ds,ans,target);
        return ans;
    }
};