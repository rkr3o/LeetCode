class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeCount;
            int samePoint = 0; // Count of points with the same coordinates as points[i]

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    samePoint++;
                } else {
                    int gcd = __gcd(dx, dy);
                    string slope = to_string(dx / gcd) + "_" + to_string(dy / gcd);
                    slopeCount[slope]++;
                }
            }

            int maxInLine = samePoint;
            for (const auto& kvp : slopeCount) {
                maxInLine = max(maxInLine, kvp.second + samePoint);
            }

            res = max(res, maxInLine);
        }

        return res + 1; // Add 1 to include the point itself.
    }
};
