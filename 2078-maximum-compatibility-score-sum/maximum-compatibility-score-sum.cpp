class Solution {
public:
    int ans = 0;
    vector<int> vis;
    void solve(int i, int score, vector<vector<int>>& s, vector<vector<int>>& m) {
        if (i == s.size()) {
            ans = max(ans, score);
            return;
        }
        for (int j = 0; j < s.size(); j++) {
            if (!vis[j]) 
            {
                vis[j] = 1;
                int st = 0;
                for (int k = 0; k < s[0].size(); k++) {
                    if (s[i][k] == m[j][k]) {
                        st += 1;
                    }
                }
                solve(i + 1, score + st, s, m);
                vis[j] = 0;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vis.assign(students.size(), 0);
        solve(0, 0, students, mentors);
        return ans;
    }
};
