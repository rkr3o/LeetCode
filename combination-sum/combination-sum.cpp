class Solution {
public:
    void solve(int idx , vector<int>&nums , int t , vector<int>&ds , vector<vector<int>>&ans)
    {
        if(t==0)
        {
            ans.push_back(ds);
            return;
        }
        if(idx>=nums.size())return;
        //pick 
        if(nums[idx]<=t)
        {
              ds.push_back(nums[idx]);
              solve(idx,nums,t-nums[idx],ds,ans);
              ds.pop_back();
        }
        //not pick
        solve(idx+1,nums,t,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,candidates,target,ds,ans);
        return ans;
    }
};