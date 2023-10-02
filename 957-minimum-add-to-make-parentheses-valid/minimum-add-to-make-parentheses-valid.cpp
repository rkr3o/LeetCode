class Solution {
public:
    int minAddToMakeValid(string s) {
         stack<char>st;
         int cnt = 0 ;
         for(auto x :s)
         {
             if(x=='(')
             {
                 st.push(x);
             }
             else if(x==')')
             {
                 if(st.empty())
                 {
                     cnt++;
                 }
                 else if(st.top()=='(')
                 {
                     st.pop();
                 }
             }
         }
         return st.size()+cnt;
    }
};