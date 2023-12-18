class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
      //  for(auto x : nums)cout<<x<<" ";
        return abs((nums[1]*nums[0])-(nums.back()*nums[n-2]));
    }
};