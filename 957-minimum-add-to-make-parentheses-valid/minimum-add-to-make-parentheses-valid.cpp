class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char>st;
        for(auto x : s)
        {
            if(x=='(')
            {
                st.push(x);
            }
            else 
            {
                if(st.empty())
                {
                    cnt++;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return cnt+=st.size();
    }
};