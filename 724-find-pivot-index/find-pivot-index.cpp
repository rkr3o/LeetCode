class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);

        int  curSum = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            totalSum-=nums[i];
            if(curSum==totalSum)
            {
                return i;
                break;
            }
            curSum+=nums[i];
        }
        return -1;
    }
};