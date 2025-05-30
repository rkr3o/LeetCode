class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;

        for (int x : nums1) {
            if (x == 0) z1++;
            else sum1 += x;
        }

        for (int x : nums2) {
            if (x == 0) z2++;
            else sum2 += x;
        }

        long long min1 = sum1 + z1 * 1;
        long long min2 = sum2 + z2 * 1;

        if (z1 == 0 && min2 > sum1) return -1;
        if (z2 == 0 && min1 > sum2) return -1;

        return max(min1, min2);
    }
};
