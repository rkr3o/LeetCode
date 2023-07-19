class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for(int i = 0; i < n; i++)
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        sort(workers.begin(), workers.end());
        double sum = 0, ans;
        priority_queue<int> minQualities;
        for(int i = 0; i < K; i++) {
            sum += workers[i].second;
            minQualities.push(workers[i].second);
        }
        ans = sum * workers[K - 1].first;
        for(int i = K; i < n; i++) {
            int maxQuality = minQualities.top();
            if(maxQuality > workers[i].second) {
                minQualities.pop();
                minQualities.push(workers[i].second);
                sum += workers[i].second - maxQuality;
            }
            ans = min(ans, sum * workers[i].first);
        }
        return ans;
    }
};