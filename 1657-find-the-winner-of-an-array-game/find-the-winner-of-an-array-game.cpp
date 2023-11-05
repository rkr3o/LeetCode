class Solution {
public:
    void getRightSmall(vector<int>& nums, vector<int>& right) {
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }
    }
    
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> right(n, 0);
        getRightSmall(arr, right);
        
        int currentMax = arr[0];
        int consecutiveWins = 0;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > currentMax) {
                currentMax = arr[i];
                consecutiveWins = 1;
            } else {
                consecutiveWins++;
            }
            
            if (consecutiveWins >= k) {
                return currentMax;
            }
            
            if (right[i] == n) {
                break;  // No larger element on the right
            }
        }
        
        return currentMax;  // If no winner found, the largest element will be the winner.
    }
};
