class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int t) {
         unordered_map<int, vector<int>> mp;

    // Mapping each bus stop to the routes that pass through it
    for (int i = 0; i < routes.size(); i++) {
        for (auto j : routes[i]) {
            mp[j].push_back(i);
        }
    }
    queue<pair<int, int>> q;
    q.push({src, 0});
    unordered_set<int> st = {src};
    while (!q.empty()) {
        int node = q.front().first;
        int stops = q.front().second;
        q.pop();

        if (node == t)
            return stops;

        // Iterating over the routes passing through the current bus stop
        for (auto x : mp[node]) {
            // Iterating over the bus stops in the current route
            for (auto y : routes[x]) {
                if (st.find(y) == st.end()) {
                    st.insert(y);
                    q.push({y, stops + 1});
                }
            }
            routes[x].clear();  // Marking the route as visited by clearing it
        }
    }
    return -1;  // Destination not reachable
    }
};