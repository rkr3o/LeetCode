class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int cnt = 0;
        int prev = nums[1] - nums[0];
        int cur = 0;

        for (int i = 1; i < n - 1; i++) {
            int diff = nums[i + 1] - nums[i];

            if (diff == prev) {
                cur++;
            } else {
                cnt += (cur * (cur + 1)) / 2; // Add the count for subarrays ending at the previous element
                prev = diff;
                cur = 0;
            }
        }

        cnt += (cur * (cur + 1)) / 2; // Add the count for the last set of subarrays

        return cnt;
    }
};
