class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        int ans = 0;
        if(!(a&1) and !(b&1))return 0;
        if (a&1){
            for(auto x : nums2)
                ans= ans^x;
        }
        if(b&1){
            for(auto x : nums1)
                ans= ans^x;
        }
        return ans;
    }
};