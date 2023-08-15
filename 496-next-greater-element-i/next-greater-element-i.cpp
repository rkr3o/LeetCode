class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; i++) {
            bool found = false;  // Flag to track if a greater element is found
            for (int j = 0; j < m; j++) {
                if (nums2[j] == nums1[i]) {
                    found = true;
                }
                if (found && nums2[j] > nums1[i]) {
                    ans[i] = nums2[j];  // Store the greater element
                    break;
                }
            }
        }
        
        return ans;
    }
};
