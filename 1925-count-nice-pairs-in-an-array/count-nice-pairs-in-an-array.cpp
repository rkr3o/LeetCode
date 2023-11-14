class Solution {
public:
    const int mod = 1e9 + 7;

    int rev(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));
        return stoi(s);
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - rev(nums[i]);
            cnt += mp[diff]++;
            cnt%=mod;
        }
        return cnt;
    }
};
