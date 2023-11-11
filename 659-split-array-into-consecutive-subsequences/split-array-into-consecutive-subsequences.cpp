class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, appendFreq;
        for (auto x : nums) freq[x]++;

        for (auto x : nums) {
            if (freq[x] == 0) {
                // The current number has already been used in a previous subsequence
                continue;
            } else if (appendFreq[x] > 0) {
                // Append to an existing subsequence
                appendFreq[x]--;
                appendFreq[x + 1]++;
            } else if (freq[x + 1] > 0 && freq[x + 2] > 0) {
                // Start a new subsequence
                freq[x + 1]--;
                freq[x + 2]--;
                appendFreq[x + 3]++;
            } else {
                // Cannot start a new subsequence or append to an existing one
                return false;
            }
            freq[x]--;
        }

        return true;
    }
};
