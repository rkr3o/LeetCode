class Solution
{
    public:
        int longestValidParentheses(string s)
        {

            int open = 0, close = 0;
            int maxima = 0;
           	//use index 
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                    open++;
                else
                    close++;
                if (open == close)
                    maxima = max(maxima, 2 *open);
                if (close > open)
                    open = close = 0;
            }
            open = close = 0;
            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == '(')
                    open++;
                else
                    close++;
                if (open == close)
                    maxima = max(maxima, 2 *open);
                if (open > close)
                    open = close = 0;
            }

            return maxima;
        }
};