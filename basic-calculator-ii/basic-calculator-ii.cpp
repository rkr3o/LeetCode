class Solution
{
    public:
        int calculate(string s)
        {
            stack<int> st;
            int num = 0;
            char sign ='+';
            for (int i = 0; i < s.size(); i++)
            {
                char c = s[i];
                if (isdigit(c))
                {
                    num = num*10 + (c - '0');
                }

                if ((!isdigit(c) and c != ' ') || i == s.length()-1)
                {
                    if (sign == '+')
                    {
                        st.push(num);
                    }
                    else if (sign == '-')
                    {
                        st.push(-num);
                    }
                    else if (sign == '*')
                    {
                        int topEle = st.top();
                        st.pop();
                        st.push(topEle*num);
                    }
                    else if (sign == '/')
                    {
                        int topEle = st.top();
                        st.pop();
                        st.push(topEle / num);
                    }
                    num = 0;
                    sign=c;
                }
            }
            int result = 0;
            while (!st.empty())
            {
                result += st.top();
                st.pop();
            }

            return result;
        }
};