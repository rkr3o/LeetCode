class FindSumPairs {
public:
    vector<int> a;
    vector<int> b;
    unordered_map<int, int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
       a = nums1;
       b = nums2;
        for (auto x : nums2) {
            mp[x]++;
        }
    }
    void add(int index, int val) {
        int oldVal = b[index];
        mp[oldVal]--;
        b[index] += val;
        mp[b[index]]++;
    }

    int count(int tot) {
        int countPairs = 0;
        for (auto num : a) {
            int complement = tot - num;
            if (mp.find(complement) != mp.end()) {
                countPairs += mp[complement];
            }
        }
        return countPairs;
    }
};
