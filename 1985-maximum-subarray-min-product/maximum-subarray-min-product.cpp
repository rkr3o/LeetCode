class Solution {
public:
    const int mod = 1e9 + 7;
    void getLeftSmall(vector<int>& nums, vector<int>& left) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }
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
            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }
            st.push(i);
        }
    }
    long long maxSumMinProduct(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftSmall(n, 0);
        vector<int> rightSmall(n, 0);
        getLeftSmall(arr, leftSmall);
        getRightSmall(arr, rightSmall);
        long long ans = 0;
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + arr[i];
        }
        for (int i = 0; i < n; i++) {
            int l = leftSmall[i];
            int r = rightSmall[i];
            long long s = pre[r]-pre[l+1];
            ans = max(ans, s * arr[i]);
        }
        return ans % mod;
    }
};
