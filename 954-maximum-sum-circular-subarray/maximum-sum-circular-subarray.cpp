class Solution {
public:
    int kadanes(vector<int>&nums)
    {
        int sum = 0 ;
        int best = nums[0];
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum+=nums[i];
            best = max(sum,best);
            if(sum<0)
            {
                sum = 0 ;
            }
        }
        return best;
    }
    int maxSubarraySumCircular(vector<int>& nums) {

      int n = nums.size();
      int plainSum = kadanes(nums);
      if(plainSum<0)return plainSum;
      int sum = 0 ;
      for(int i = 0 ; i < nums.size() ; i++)
      {
          sum+=nums[i];
          nums[i]=-nums[i];
      }   
      int circularSum = sum+kadanes(nums);
      return max(circularSum,plainSum);
    }
};
 