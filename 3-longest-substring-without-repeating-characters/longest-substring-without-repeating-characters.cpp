class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxima = 0 ; 
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            unordered_set<char>st;
            string temp="";
            for(int j = i; j < n ; j++)
            {
                temp+=s[j];
                if(st.find(s[j])==st.end())
                {
                    st.insert(s[j]);
                    maxima = max(maxima,(int)temp.size());
                }
                else
                { 
                    break;
                }
            }
        }
        return  maxima;
    }
};