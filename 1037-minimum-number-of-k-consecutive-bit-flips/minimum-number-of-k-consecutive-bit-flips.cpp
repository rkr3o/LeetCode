class Solution {
public:
    int minKBitFlips(vector<int>& array, int k) {
        int flipped = 0;
        int length = array.size();
        int res = 0;

        for (int i = 0; i < length; i++) {
            // Revise flipped which didn't affect the current index
            if (i >= k && array[i - k] < 0) {
                flipped ^= 1;
            }

            // Use ^ to know whether array[i] needs to be flipped or not
            if (!(flipped ^ array[i])) {
                // If the current index still needs a flip,
                // and the sliding window will be over the length
                if (i + k > length) return -1;

                array[i] = -1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};
