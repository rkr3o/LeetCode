class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        
        vector<int> merged(n + m);
        int i = 0, j = 0, k = 0;
        
        while (k < n + m) {
            if (nums1[i] <= nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        
        if ((n + m) % 2 == 1) {
            return merged[(n + m) / 2];
        } else {
            return (double)(merged[(n + m) / 2 - 1] + merged[(n + m) / 2]) / 2;
        }
    }
};
