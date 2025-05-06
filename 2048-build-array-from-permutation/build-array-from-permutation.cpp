class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        unordered_map<int,int>mp;
        for(int i=0; i < n; i++){
            mp[i]=nums[i];
        }
        for(int i = 0 ; i < n ;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans[i] = mp[nums[i]];
            }
        }
        return ans;
    }
};