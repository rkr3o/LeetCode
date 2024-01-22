class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(k==0)return 0 ;
        int maxima = 1;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int right = 0 , left = 0 ; right < n ;right++)
        {
            mp[nums[right]]++;
            while(mp[nums[right]]>k)
            {
                mp[nums[left]]--;
                left++;
                if(mp[nums[left]]==0)mp.erase(mp[nums[left]]);
            }
            maxima = max(maxima,right-left+1);
        }
        return maxima;
    }
};