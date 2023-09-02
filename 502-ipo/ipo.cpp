class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        vector<pair<int, int>> projects;
        priority_queue<int> minCapitalHeap;
        for (int i = 0; i < profits.size(); ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        int n = projects.size();
        while (k > 0) {
            while (i < n && projects[i].first <= w) {
                minCapitalHeap.push(projects[i].second);
                i++;
            }
            if (!minCapitalHeap.empty()) {
                w += minCapitalHeap.top();
                minCapitalHeap.pop();
            } else {
                break;
            }
            k--;
        }
      return w;
    }
};
