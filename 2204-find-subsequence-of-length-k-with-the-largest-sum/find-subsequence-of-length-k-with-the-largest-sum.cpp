class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // Add elements with their indices to the priority queue
    for (int i = 0; i < nums.size(); i++) {
        q.push({nums[i], i});
        if (q.size() > k) {
            q.pop();
        }
    }
    // Create a set to keep track of unique indices
    set<int> index;
    // Add the indices to the set since indices are unique
    while (!q.empty()) {
        pair<int, int> top = q.top();
        index.insert(top.second);
        q.pop();
    }
    // Initialize the result vector
    vector<int> result(k);
    
    // Add elements to the result for the indices present in the set
    int p = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (index.count(i)) {
            result[p] = nums[i];
            p++;
        }
    }
    return result;
    }
};