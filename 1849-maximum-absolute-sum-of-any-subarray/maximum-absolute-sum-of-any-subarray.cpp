class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxima = 0;
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum < 0) {
                sum = 0;
            }
            maxima = max(maxima, abs(sum));

        }
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += -nums[i];
            if (sum < 0) {
                sum = 0;
            }
            maxima = max(maxima, abs(sum));

        }
        return maxima;
    }
};
