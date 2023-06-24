class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
         std::unordered_set<int> numSet;
    int longestStreak = 0;

    // Add all elements from nums to numSet
    for (int num : nums) {
        numSet.insert(num);
    }

    // Iterate through each element in nums
    for (int num : nums) {
        // Check if num - 1 is not present in numSet
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;

            // Increment currentNum and check if it is present in numSet
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentStreak += 1;
            }

            // Update longestStreak if necessary
            longestStreak = std::max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
        }
};