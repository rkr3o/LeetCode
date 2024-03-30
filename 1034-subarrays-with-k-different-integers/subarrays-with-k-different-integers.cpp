class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int total = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int right = 0, left = 0; right < n; ++right) {
            mp[nums[right]]++;
            while (mp.size() > k) 
            {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) 
                {
                    mp.erase(nums[left]);
                }
                left++;
            } 
            total+=right-left+1; 
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};