class Solution {
public:
    int calculate(string s) 
    {
        stack<int>st;
        int num = 0 ;
        char sign='+';
        for(int i = 0 ; i < s.size() ; i++)
        {
            char x = s[i];
            if(isdigit(x))
            {
                num = num*10+(x-'0');
            }

            if(!isdigit(x) and x !=' ' || i==s.size()-1)
            {
                if(sign=='+')
                {
                    st.push(num);
                }
                else if(sign=='-')
                {
                    st.push(-num);
                }
                else if(sign=='*')
                {
                    int prev = st.top();
                    st.pop();
                    st.push(num*prev);
                }
                else if(sign=='/')
                {
                    int prev = st.top();
                    st.pop();
                    st.push(prev/num);
                }

                num = 0 ;
                sign = x;
            }
        }
        int ans =  0 ;
        while(!st.empty())
        {
             ans+=st.top();
             st.pop();
        }
        return ans;
    }
};