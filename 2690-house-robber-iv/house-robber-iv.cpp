class Solution {
public:
    bool good(vector<int>& nums, int k,int mid)
    {
        int n = nums.size();
        for(int i = 0 ; i < n ;i++)
        {
             if(nums[i]<=mid)
             {
                 i++;
                 k--;
             }
             if(k==0)return true;
        }
        return k == 0;
    }
    int minCapability(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int low = 0,high = 1e9+10;
        int ans =-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(good(nums, k, mid)) 
             {
                 ans = mid;
                 high = mid-1;
             }
            else 
            {
                low=mid+1;
            }
        }
        return ans;
    }
};