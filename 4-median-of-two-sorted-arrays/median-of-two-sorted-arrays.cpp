class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           for(auto x : nums2)
           {
              nums1.push_back(x);
           }
           sort(nums1.begin(),nums1.end());
           int n = nums1.size();
           if(n&1)
           {
                int mid = n/2;
                return nums1[n/2];
           }
           else
           {    
                int mid = n/2;
                return (double)(nums1[mid-1]+nums1[mid])/2;
           }
    }
};