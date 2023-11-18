class Solution {
public:
    using ll = long long  ;
    int maxFrequency(vector<int>& nums, int k) {
        ll maxima = 0;
        ll sum = 0 ;
        sort(begin(nums),end(nums));
        for(int right = 0 , left = 0 ; right<nums.size() ; right++)
        {
            sum+=nums[right];
            while(((long long)nums[right]*(right-left+1)-sum) > k)
            {
                sum-=nums[left];
                left++;
            }
            maxima = max(maxima,(ll)right-left+1);
        }
        return maxima;
    }
};