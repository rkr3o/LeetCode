class Solution {
public:
void solve(int ind , vector<int>&nums,set<vector<int>>&ans)
    {
        if(ind==nums.size())
        {
            ans.insert(nums);
            return;
        }
        for(int i = ind ; i < nums.size() ; i++)
        {
            swap(nums[i],nums[ind]);
            solve(ind+1,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }
        
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         
        set<vector<int>>ans;
        solve(0,nums,ans);
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};