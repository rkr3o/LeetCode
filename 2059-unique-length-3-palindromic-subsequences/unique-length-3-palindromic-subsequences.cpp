class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letter;
        int cnt = 0;
        int n = s.size();
        for (auto x : s) letter.insert(x);
        vector<int> left(26, -1), right(26, -1);
        for (int i = 0; i < n; i++) {
            if (left[s[i] - 'a'] == -1) left[s[i] - 'a'] = i;
            right[s[i] - 'a'] = i;  // Fix the typo here
        }
        for (auto x : letter) {
            int l = left[x - 'a'];
            int r = right[x - 'a'];
            unordered_set<char> st;
            for (int mid = l + 1; mid < r; mid++) {
                st.insert(s[mid]);
            }
            cnt += st.size();
        }
        return cnt;
    }
};
