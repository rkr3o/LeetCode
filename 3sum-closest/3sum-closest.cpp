#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3)
            return 0; // or any default value

        sort(nums.begin(), nums.end()); // Sort the input array

        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize closestSum with the sum of the first three elements

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1; // Pointer for the element after nums[i]
            int right = n - 1; // Pointer for the last element

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target) {
                    // If the sum is equal to the target, return the sum
                    return currentSum;
                } else if (abs(currentSum - target) < abs(closestSum - target)) {
                    // Update closestSum if the current sum is closer to the target
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    // If the current sum is less than the target, move the left pointer to the right
                    left++;
                } else {
                    // If the current sum is greater than the target, move the right pointer to the left
                    right--;
                }
            }
        }

        return closestSum;
    }
};
