class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        if(n&1)return -1;
        sort(nums.begin(),nums.end());
        int i = 0 ,j = n-1;
        int maxima = 0;
        while(i<j)
        {
            maxima = max(maxima,nums[i++]+nums[j--]);
        }
        return maxima;
    }
};