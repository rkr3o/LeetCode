class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> Ans;
        
        if (n <= 1) {
            return Ans;
        }
        
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                Ans.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return Ans;
    }
};
