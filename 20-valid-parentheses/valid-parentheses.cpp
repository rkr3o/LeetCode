class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x : s)
        {
            if(x=='(' || x=='{' || x=='[')
            {
                st.push(x);
            }
            else{
                    if(st.empty())return false;
                    if(x==')' and st.top()!='(' || x=='}' and st.top()!='{' || x==']' and st.top()!='[' || st.empty())
                    {
                        return false;
                    }
                    else
                    {
                        st.pop();
                    }
            }
        }
        if(!st.empty())return false;
        return true;
    }
};