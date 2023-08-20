class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
         int n = nums.size();
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        int target = sum % p;
        if (target == 0) {
            return 0; // No need to remove any subarray
        }
        
        unordered_map<int, int> mp;
        mp[0] = -1; // Initial remainder of 0 is achieved before the first element
        
        int pre = 0;
        int minLength = n;

        for (int i = 0; i < n; i++) 
        {
            pre = (pre + nums[i]) % p;
            int req = (pre - target + p) % p;
            if (mp.find(req) != mp.end()) {
                int len = i - mp[req];
                minLength = min(minLength, len);
            }
            mp[pre] = i;
        }
        if (minLength == n) {
            return -1; // It's impossible to find a valid subarray to remove
        }
        return minLength;
    }
};