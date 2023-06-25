class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         int n = nums.size();
    if (n <= 1) {
        return 0; // Empty array or array of size 1 cannot have a subarray with equal 0s and 1s
    }

    int max_length = 0;
    int count = 0;
    unordered_map<int, int> count_map;
    count_map[0] = -1;

    for (int i = 0; i < n; i++) {
        count += (nums[i] == 0) ? -1 : 1;

        if (count_map.find(count) != count_map.end()) {
            max_length = std::max(max_length, i - count_map[count]);
        } else {
            count_map[count] = i;
        }
    }

    return max_length;
    }
};