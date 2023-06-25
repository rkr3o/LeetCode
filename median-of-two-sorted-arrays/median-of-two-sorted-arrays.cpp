class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Ensure nums1 is the smaller array
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left = 0;
        int right = n;
        int partitionX, partitionY;
        int maxLeftX, maxLeftY, minRightX, minRightY;

        while (left <= right) {
            partitionX = (left + right) / 2;
            partitionY = (n + m + 1) / 2 - partitionX;

            maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            minRightX = (partitionX == n) ? INT_MAX : nums1[partitionX];

            maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            minRightY = (partitionY == m) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                return (n + m) % 2 == 0 ? (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
                                        : max(maxLeftX, maxLeftY);
            } else if (maxLeftX > minRightY) {
                right = partitionX - 1;
            } else {
                left = partitionX + 1;
            }
        }

        // This should not happen if the input is valid
        return -1;
    }
};
