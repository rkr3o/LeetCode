class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); ++i) {
            bool destroyed = false;
            for (int j = ans.size() - 1; j >= 0; --j) {
                if (asteroids[i] > 0 || ans[j] < 0) {
                    break;  // No further collisions possible
                }
                if (abs(ans[j]) == abs(asteroids[i])) {
                    ans.pop_back();
                    destroyed = true;
                    break;
                } else if (abs(ans[j]) > abs(asteroids[i])) {
                    destroyed = true;
                    break;
                } else {
                    ans.pop_back();
                }
            }
            if (!destroyed) {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};
