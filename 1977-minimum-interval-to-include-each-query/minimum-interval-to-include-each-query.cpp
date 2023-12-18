class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, int> result;
		vector<int> res;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>  > pq;
		int i = 0;
		int n = intervals.size();
        vector<int> copyQueries = queries;
		
        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());
   				
        for (int q: queries) {
            while (i < n && intervals[i][0] <= q) {
                if(intervals[i][1] >= q){
                    int size = intervals[i][1] - intervals[i][0] + 1;
                    pq.push({size, intervals[i][1]});
                }
                i++;
            }
            while (!pq.empty() && pq.top().second < q) {
                    pq.pop();
            }
            if (!pq.empty()) {
                result[q] = pq.top().first;
            } else {
                result[q]= -1;
            }
        }
        for (int i = 0; i < copyQueries.size(); i++) {
            res.push_back(result[copyQueries[i]]);
        }
        return res;
    }
};