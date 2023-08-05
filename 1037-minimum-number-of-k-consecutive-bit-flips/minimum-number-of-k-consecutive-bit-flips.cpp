class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        vector<int> flipped(n, 0);

        int flips = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flips ^= flipped[i - k];
            }

            if ((nums[i] + flips) % 2 == 0) {
                if (i + k > n) {
                    return -1;
                }
                flipped[i] = 1;
                flips ^= 1;
                res++;
            }
        }

        return res;
    }
};
