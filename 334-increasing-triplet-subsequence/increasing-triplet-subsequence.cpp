class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return false;
        vector<int>right(n,INT_MIN);
        vector<int>left(n,INT_MAX);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i = 1 ; i<n ; i++)
        {
            left[i]=min(nums[i],left[i-1]);
        }
        for(int i = n-2 ; i>=0 ; i--)
        {
            right[i]=max(nums[i],right[i+1]);
        }

        for(int i = 1 ; i < n-1 ; i++)
        {
            if(nums[i] > left[i-1] and nums[i]<right[i+1])return true;
        }
         
        return false;
    }
};