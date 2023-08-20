class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

       unordered_map<int, int> mp;
       int cnt = 0;
       mp[0] = 1;
       int pre = 0;
       
       int n = nums.size();  // You forgot to declare and initialize 'n'

       for(int i = 0; i < n; i++) {
           pre += nums[i];
           int req = (pre % k + k) % k;  // Calculate the remainder
           if (mp.find(req) != mp.end()) {
               cnt += mp[req];  // Add the count of subarrays with the same remainder
           }

           mp[req]++;  // Update the remainder count in the map
       }   
       
       return cnt;
    }
};
