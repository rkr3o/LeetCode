class Solution {
public:
    long long val(vector<int>& arr) {
        long long cur = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cur += static_cast<long long>(arr[i]) * i;
        }
        return cur;
    }

    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long cur = val(nums);

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        long long maxima = cur;

        for (int i = 1; i < n; i++) {
            cur = cur + sum - static_cast<long long>(n) * nums[n - i];
            maxima = max(maxima, cur);
        }

        return static_cast<int>(maxima);
    }
};
