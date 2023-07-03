class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 2)
            return 0;
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicate elements

            int j = i + 1, h = n - 1;
            while (j < h) {
                int currentSum = nums[i] + nums[j] + nums[h];
                if (currentSum == target)
                    return currentSum;
                else if (abs(currentSum - target) < abs(closestSum - target))
                    closestSum = currentSum;
                if (currentSum < target) {
                    j++;
                    while (j < h && nums[j] == nums[j - 1])
                        j++; // Skip duplicate elements
                } else {
                    h--;
                    while (j < h && nums[h] == nums[h + 1])
                        h--; // Skip duplicate elements
                }
            }
        }
        return closestSum;
    }
};
