#include <string>
#include <unordered_set>

class Solution {
public:
    string removeDuplicateLetters(string s) {
          string res;
        unordered_map<char, int> last;
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }
        vector<char> vis(26, 0);
        stack<char> st;
        for (int i = 0; i < (int)s.size(); i++) {
            char ch = s[i];
            if (vis[ch - 'a']) continue;
            while (!st.empty() && st.top() > ch && i < last[st.top()]) {
                vis[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(ch);
            vis[ch - 'a'] = 1;
        }
        while (!st.empty()) {
            res += st.top();
            st.pop(); // Pop the elements from the stack
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
