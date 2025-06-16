class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minima = nums[0];
        int maxDif = -1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > minima) {
                maxDif = max(maxDif, nums[i] - minima);
            } else {
                minima = nums[i];
            }
        }

        return maxDif;
    }
};
