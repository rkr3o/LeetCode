class Solution {
public:
    using ll = long long;

    void getLeftSmall(vector<int>& nums, vector<int>& left) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
    }
    void getRightSmall(vector<int>& nums, vector<int>& right) {
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) { // Change '>' to '>='
                st.pop();
            }
            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
    }
    void getLeftGreater(vector<int>& nums, vector<int>& left) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();
            st.push(i);
        }
    }

    void getRightGreater(vector<int>& nums, vector<int>& right) {
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
    }

    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftSmall(n, n);
        vector<int> rightSmall(n, n);
        vector<int> leftGreater(n, n);
        vector<int> rightGreater(n, n);
        getLeftSmall(arr, leftSmall);
        getRightSmall(arr, rightSmall);
        getLeftGreater(arr, leftGreater); // Corrected function call
        getRightGreater(arr, rightGreater);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ll ls = i - leftSmall[i];
            ll rs = rightSmall[i] - i;
            ll lg = i - leftGreater[i];
            ll rg = rightGreater[i] - i;
            long long totalsum = ((lg*rg)-(ls*rs))*arr[i];
            ans += totalsum;
        }
        return ans;
    }
};
