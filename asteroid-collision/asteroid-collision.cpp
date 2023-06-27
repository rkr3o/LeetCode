class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            if (ans.empty() || asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
            } else {
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])) {
                    ans.pop_back();
                }
                if (ans.empty() || ans.back() < 0) {
                    ans.push_back(asteroids[i]);
                } else if (ans.back() == -asteroids[i]) {
                    ans.pop_back();
                }
            }
        }

        return ans;
    }
};
