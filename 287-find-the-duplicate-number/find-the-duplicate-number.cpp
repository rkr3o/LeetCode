class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                return abs(nums[i]); // Duplicate found
            else
                nums[index] *= -1; // Mark as visited
        }
        return -1; 
    }
};