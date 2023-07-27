class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> ans;
        solve(0, s, "", st, ans);
        return ans;
    }

    void solve(int ind, string& s, string req, unordered_set<string>& st, vector<string>& ans) {
        if (ind == s.size()) {
            ans.push_back(req);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            string cur = s.substr(ind, i - ind + 1);
            if (st.find(cur) != st.end()) {
                if (req.empty()) {
                    solve(i + 1, s, cur, st, ans);
                } else {
                    solve(i + 1, s, req + " " + cur, st, ans);
                }
            }
        }
    }
};
