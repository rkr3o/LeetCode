class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0;
        int cnt = 0;
        int x = nums.size();
        long long sum = 1;
        while (sum <= n) {
            if (i < x && nums[i] <= sum) {
                sum += nums[i];
                i++;
            } else {
                sum += sum;
                cnt++;
            }
        }
        return cnt;
    }
};
