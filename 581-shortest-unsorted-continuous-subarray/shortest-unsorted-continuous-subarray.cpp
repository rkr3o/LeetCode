class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int pre = -1;
        int suff=-1;
        vector<int>nums2=nums;
        sort(nums2.begin(),nums2.end());
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]!=nums2[i] and pre==-1)
            {
                pre = i;
            }
            else if(nums[i]!=nums2[i] and pre!=-1)
            {
                suff=i;
            }
        }
        if(pre!=-1 and suff!=-1)return suff-pre+1;
        return 0;
    }
};