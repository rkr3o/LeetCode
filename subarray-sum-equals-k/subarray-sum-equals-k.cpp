class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {   
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] == k;
        
        int cnt = 0;  // Counter for the number of valid subarrays
        int sum = 0;  // Cumulative sum
        unordered_map<int, int> mp;  // Map to store frequencies of cumulative sums
        mp[0]++;  // Initialize the frequency of 0 as 1, to handle subarrays starting from index 0
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];  // Calculate the cumulative sum
            
            int req = sum - k;  // Calculate the required value (sum - k) to reach the desired sum
            
            if (mp.find(req) != mp.end()) {
                cnt += mp[req];  // Increment the counter by the frequency of the required value
            }
            
            mp[sum]++;  // Update the frequency of the cumulative sum
        }

        return cnt;
    }
};
