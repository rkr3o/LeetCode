class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxima =0 ;
        unordered_set<char>st;
        int l = 0;
        for(int r = 0 ; r < s.size() ; r++)
        {
             if(st.find(s[r])==st.end())
             {
                 st.insert(s[r]);
                 maxima = max(maxima , r-l+1);
             }
             else
             {
                 while (s[l] != s[r]) {
                    st.erase(s[l]);
                    l++;
                }
                 //st.erase(s[r]);
                 l++;
             }
        }
        return maxima;
    }
};