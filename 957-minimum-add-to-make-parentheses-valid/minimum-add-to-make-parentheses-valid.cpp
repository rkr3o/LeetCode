class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char>st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    count++; // Count unmatched closing parenthesis
                } else {
                    st.pop(); // Match with a corresponding opening parenthesis
                }
            }
        }
        
        // Count unmatched opening parenthesis
        count += st.size();
        
        return count;
    }
};