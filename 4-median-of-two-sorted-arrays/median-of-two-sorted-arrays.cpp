class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> v;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j])
                v.push_back(nums1[i++]);
            else
                v.push_back(nums2[j++]);
        }
        while (i < n) v.push_back(nums1[i++]);
        while (j < m) v.push_back(nums2[j++]);
        int nn = v.size();
        double mid = (n + m) / 2.0;  
        if (nn % 2 == 1) {
            return v[mid];
        } else {
            double x = v[mid] + v[mid - 1];
            return x / 2.0; 
        }
        return 0;
    }
};
