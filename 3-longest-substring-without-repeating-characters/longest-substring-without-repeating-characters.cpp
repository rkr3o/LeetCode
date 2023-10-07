class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int left = 0 ;
        int maxima = 0;
        for(int right = 0 ; right < s.size() ; right++)
        {
            if(st.find(s[right])!=st.end())
            {
                while(left < right and st.find(s[right])!=st.end())
                {
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
            maxima = max(maxima,right-left+1);
        }
        return maxima;
    }
};