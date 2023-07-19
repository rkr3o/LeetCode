class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers; // Stores the wage-to-quality ratio and the quality of each worker

        // Calculate the wage-to-quality ratio for each worker and store it in the 'workers' vector
        for (int i = 0; i < n; ++i) {
            double ratio = (double)(wage[i]) / quality[i];
            workers.emplace_back(ratio, quality[i]);
        }

        // Sort the 'workers' vector based on the wage-to-quality ratio in ascending order
        sort(workers.begin(), workers.end());

        double minCost = DBL_MAX; // Initialize the minimum cost to a large value
        int qualitySum = 0; // Stores the sum of k-1 smallest qualities
        priority_queue<int> pq; // A max heap to keep track of the k-1 smallest qualities

        // Iterate through each worker in the sorted order
        for (const auto& worker : workers) {
            qualitySum += worker.second; // Add the quality of the current worker to the sum
            pq.push(worker.second); // Add the quality to the max heap

            // If the number of workers in the max heap exceeds k, remove the worker with the largest quality
            if (pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }

            // If we have exactly k workers in the max heap, we have a valid paid group
            if (pq.size() == k) {
                // Calculate the cost by multiplying the sum of k-1 smallest qualities with the wage-to-quality ratio
                double cost = qualitySum * worker.first;
                // Update the minimum cost if the current cost is smaller
                minCost = min(minCost, cost);
            }
        }

        return minCost; // Return the minimum cost to form a paid group satisfying the given conditions
    }
};
