class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t!=1;
        }
        int dx = abs(fx - sx);
        int dy = abs(fy - sy);
        int min_moves = max(dx, dy);
        return t >= min_moves;
    }
};