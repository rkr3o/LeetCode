class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxima =  0 ;
        //use index 
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i]=='(')//valid start
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())st.push(i);
                maxima = max(maxima,i-st.top());
            }
        }

        return maxima;
    }
};