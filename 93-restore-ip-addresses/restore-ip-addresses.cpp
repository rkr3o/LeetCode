class Solution {
public:
 bool isValid(string &s) {
        if (s.empty() || s.size() > 3) return false;
        if (s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    void solve(int ind, string &s, vector<string> &ans, string ds, int dotCount) {
        if (dotCount == 3) {
            string remaining = s.substr(ind);
            if (isValid(remaining)) {
                ans.push_back(ds + remaining);
            }
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            string segment = s.substr(ind, i - ind + 1);
            if (isValid(segment)) {
                if (dotCount < 3) {
                    solve(i + 1, s, ans, ds + segment + '.', dotCount + 1);
                } else {
                    solve(i + 1, s, ans, ds + segment, dotCount);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ds;
        solve(0, s, ans, ds, 0);
        return ans;
    }
};