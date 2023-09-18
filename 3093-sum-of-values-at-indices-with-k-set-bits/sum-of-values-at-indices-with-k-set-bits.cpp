class Solution {
public:
    int setBits(int i)
    {
        return __builtin_popcount(i);
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0 ;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (setBits(i) == k)
            {
                sum += nums[i];
            }
        }
        return sum;
    }
};