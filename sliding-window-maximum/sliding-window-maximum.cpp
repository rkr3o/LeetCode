#include <vector>
#include <queue>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();

        // Custom comparator to make the priority queue act as a max heap
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<int> result;

        for (int i = 0; i < k; i++)
            pq.push({v[i], i});

        result.push_back(pq.top().first);

        for (int i = k; i < n; i++) {
            pq.push({v[i], i});

            while (pq.top().second <= i - k)
                pq.pop();

            result.push_back(pq.top().first);
        }

        return result;
    }
};
