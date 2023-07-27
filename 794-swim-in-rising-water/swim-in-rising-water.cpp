class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        auto compare = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(compare)> pq(compare);
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> seen(n, vector<int>(n, 0));
        seen[0][0] = 1;
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (true) {
            auto p = pq.top();
            pq.pop();
            int t = p.first;
            int x = p.second.first;
            int y = p.second.second;

            res = max(res, t);

            if (x == n - 1 && y == n - 1)
                return res;

            for (auto& d : dir) {
                int i = x + d[0];
                int j = y + d[1];

                if (i >= 0 && i < n && j >= 0 && j < n && !seen[i][j]) {
                    seen[i][j] = 1;
                    pq.push({grid[i][j], {i, j}});
                }
            }
        }
    }
};
