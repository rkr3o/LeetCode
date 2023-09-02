class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqMap;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freqMap[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freqMap[oldVal]--;
        nums2[index] += val;
        freqMap[nums2[index]]++;
    }

    int count(int tot) {
        int countPairs = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freqMap.find(complement) != freqMap.end()) {
                countPairs += freqMap[complement];
            }
        }
        return countPairs;
    }
};
