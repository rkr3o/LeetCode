class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n = nums.size();
        for(int i = n-1 ; i >= 1 ; i--)
        {
            if(nums[i]==nums[i-1])continue;
            ans+=(n-i);
        }
        return  ans;
    }
};