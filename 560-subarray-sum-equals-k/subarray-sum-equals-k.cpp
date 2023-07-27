class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]++;
        int res = 0;
        int sum = 0 ;
         int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] == k;
        for(int i = 0 ; i < nums.size() ; i++)
        {
             sum += nums[i];
             int req =  (sum-k);
             if(mp.find(req)!=mp.end())
             {
                 res+=mp[req];
             }
             mp[sum]++;
        }
        return res;
    }
};