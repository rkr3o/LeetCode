class Solution {
public:
    int calculate(string s) 
    {
        stack<int>nums;
        stack<char>op;
        int result = 0 ;
        int num = 0 ;
        int sign = 1;
        for(auto c : s)
        {
            if(isdigit(c))
            {
                num = num*10+(c-'0');
            }
            else
            {
                result+=sign*num;
                num= 0 ;
                if(c=='+')
                {
                    sign=1;
                }
                else if(c=='-')
                {
                    sign =-1;
                }
                else if(c=='(')
                {
                    nums.push(result);
                    op.push(sign);
                    result = 0;
                    sign =1;
                }
                else if(c==')')
                {
                    result = op.top()*result+nums.top();
                    op.pop();
                    nums.pop();
                }
            }
        }
        return result+(sign*num);
    }
};