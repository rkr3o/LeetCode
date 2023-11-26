class Solution {
public:
    void getLeftSmall(vector<int>& nums, vector<int>& left) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
    }
    void getRightSmall(vector<int>& nums, vector<int>& right) {
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftSmall(n, 0);
        vector<int> rightSmall(n, 0);
        getLeftSmall(arr, leftSmall);
        getRightSmall(arr, rightSmall);
        int area = 0;
        for (int i = 0; i < n; i++) {
            int l = leftSmall[i];
            int r = rightSmall[i];
            area = max(area, (r - l - 1) * arr[i]);
        }
        return area;
    }
    int largestSubmatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        int n = mat.size();
        int m = mat[0].size();
        int maxArea = 0;
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) { // Compare with integer 1, not character '1'
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            auto b = height;
            sort(begin(b), end(b));
            int area = sumSubarrayMins(b);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
