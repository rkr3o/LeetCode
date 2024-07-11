class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string tmp = "";

        for (char x : s) {
            if (x == '(') {
                st.push(tmp);
                tmp = "";
            } else if (x == ')') {
                reverse(tmp.begin(), tmp.end());
                if (!st.empty()) {
                    tmp = st.top() + tmp;
                    st.pop();
                }
            } else {
                tmp += x;
            }
        }

        return tmp;
    }
};
