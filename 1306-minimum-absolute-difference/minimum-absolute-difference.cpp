class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        int minima = INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i = 1; i < n; i++) {
           minima = min(minima, abs(arr[i] - arr[i-1]));
        }
        for(int i = 1; i < n; i++) {
             if(arr[i]-arr[i-1]==minima)
               ans.push_back({arr[i-1], arr[i]});      
        }
        // Sort the entire result in ascending order
       //sort(ans.begin(), ans.end());
       return ans;
    }
};
