class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        vector<int> ans;
        unordered_map<int, int> res;
        vector<int> copyQuery = queries;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        sort(begin(copyQuery), end(copyQuery));
        sort(begin(intervals), end(intervals));

        for (auto q : copyQuery) {
            while (i < n && intervals[i][0] <= q) {
                int val = abs(intervals[i][0] - intervals[i][1]) + 1;
                pq.push({val, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }
            if (!pq.empty()) {
                res[q] = pq.top().first;
            } else {
                res[q] = -1;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(res[queries[i]]);
        }
        return ans;
    }
};
