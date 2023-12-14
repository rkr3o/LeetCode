class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maximumSum = INT_MIN;
        int curSum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            curSum+=nums[i];
            maximumSum = max(curSum,maximumSum);
            if(curSum<0)
            {
                curSum=0;
            }
        }
        return maximumSum;

    }
};