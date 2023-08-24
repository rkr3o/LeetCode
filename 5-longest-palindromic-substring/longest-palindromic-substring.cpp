 class Solution {
public:

    bool checkPalindrome(string &s) {
        int l = 0;
        int h = s.size() - 1;

        while (l <= h) {
            if (s[l++] != s[h--]) return false;
        }
        return true;
    }
 void solve(int ind, string &s, string &ans) {
        if (ind >= s.size()) return;
        int n = s.size();
        string temp;
        for (int i = ind; i < n; i++) {
            temp.push_back(s[i]);
            if (checkPalindrome(temp) == true) {
                if (temp.size() > ans.size()) {
                    ans = temp;
                }
            }
        }
        solve(ind + 1, s, ans);  // Move to the next index and continue the search
    }

    string longestPalindrome(string s) {
        string ans;
        solve(0, s, ans);
        return ans;
    }
};