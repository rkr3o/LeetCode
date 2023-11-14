class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>letter;
        int cnt = 0 ;
        for(auto x : s)letter.insert(x);
        for(auto x : letter)
        {
            int left = -1;
            int right = -1;
            for(int i = 0 ; i < s.size() ; i++)
            {
                if(s[i]==x)
                {
                    if(left==-1)left=i;
                    right=i;
                }
            }
            unordered_set<char>st;
            for(int mid = left+1; mid < right ; mid++)
            {
                st.insert(s[mid]);
            }
            cnt+=st.size();
        }
        return cnt;
    }
};