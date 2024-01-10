class Solution {
public:
    bool check(int start , int end , vector<int>&nums)
    {
        int n = nums.size();
        int prev = 0;
        for(int i = 0; i < n ; i++)
        {
            if(i<=end and i>=start)continue;
            if(nums[i]<=prev)return false;
            prev=nums[i];
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ;j++)
            {
                if(check(i,j,nums))cnt++;
            }
        }
        return cnt;
    }
};