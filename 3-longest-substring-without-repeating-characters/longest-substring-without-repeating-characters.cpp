class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxima = 0 ; 
        int n = s.size();
        unordered_set<char>st;
        string str="";
        int left = 0 ;
        for(int right = 0 ; right < n ; right++)
        {
            if(st.find(s[right])==st.end())
            {
                st.insert(s[right]);
                maxima = max(maxima,right-left+1);
            }
            else
            {
                while(left < right and s[left]!=s[right])
                {
                    st.erase(s[left]);
                    left++;
                }
                left++;
            }
        }
        return maxima;
    }
};