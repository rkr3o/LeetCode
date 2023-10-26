class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int left = -1;
        int right = -1;
        // Find the first element that is smaller than its left neighbor
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                left = i - 1;
                break;
            }
        }
        // If left is still -1, the array is already sorted
        if (left == -1) return 0;
        // Find the last element that is smaller than its right neighbor
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                right = i + 1;
                break;
            }
        }
        // Find the minimum and maximum values within the unsorted subarray
        int min_val = *min_element(nums.begin() + left, nums.begin() + right + 1);
        int max_val = *max_element(nums.begin() + left, nums.begin() + right + 1);
        // Expand the left and right boundaries if needed
        while (left > 0 && nums[left - 1] > min_val) {
            left--;
        }
        while (right < n - 1 && nums[right + 1] < max_val) {
            right++;
        }
        return right - left + 1;
    }
};
