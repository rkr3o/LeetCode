class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans = -1;
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        
        while (low <= high) {    
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count >= k) 
            {
                ans = mid;
                high = mid - 1; // Changed high to mid - 1
            } 
            else 
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
