class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; ++i) {
            double ratio = (double)(wage[i]) / quality[i];
            workers.emplace_back(ratio, quality[i]);
        }

        sort(workers.begin(), workers.end());

        double minCost = DBL_MAX;
        int qualitySum = 0;
        priority_queue<int> pq;

        for (const auto& worker : workers) {
            qualitySum += worker.second;
            pq.push(worker.second);

            if (pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                double cost = qualitySum * worker.first;
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};
