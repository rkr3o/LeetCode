
class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& vis, int index, int k, int curr_sum, int target) {
        if (k == 1) return true;
        if (curr_sum == target) 
            return solve(nums, vis, 0, k - 1, 0, target);

        for (int i = index; i < nums.size(); i++) {
            if (!vis[i] && curr_sum + nums[i] <= target) {
                vis[i] = 1;   
                if (solve(nums, vis, i + 1, k, curr_sum + nums[i], target)) return true;
                vis[i] = 0;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % k != 0 || k > nums.size()) return false;
        
        int target = total_sum / k;
        sort(nums.begin(), nums.end());
        if (nums[0] > target) return false;

        vector<int> vis(nums.size(), 0);
        return solve(nums, vis, 0, k, 0, target);
    }
};