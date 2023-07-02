#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k; ++i) {
            pq.push({nums[i], i});
        }

        result.push_back(pq.top().first);
       
        for (int i = k; i < n; ++i) {
            pq.push({nums[i], i});

            while (pq.top().second <= i - k) {
                pq.pop();
            }

            result.push_back(pq.top().first);
        }

        return result;
    }
};
