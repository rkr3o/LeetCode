class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0;
        int start = 0;
        int minStart = -1;
        int maxStart = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minStart = -1;
                maxStart = -1;
                start = i + 1;
            }
            if (nums[i] == minK) {
                minStart = i;
            }
            if (nums[i] == maxK) {
                maxStart = i;
            }
            if (minStart != -1 && maxStart != -1) {
                cnt += min(maxStart, minStart) - start + 1;
            }
        }
        return cnt;
    }
};
