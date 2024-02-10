class Solution {
public:
    bool checkPalindrome(string &s)
    {
        string t = s;
        reverse(begin(t),end(t));
        return s==t;
    }
    int countSubstrings(string s) {
        int cnt = 0 ;
        int n = s.size();
        for(int i = 0 ; i < (int)s.size() ; i++)
        {
            string temp="";
            for(int j = i ; j < n ; j++)
            {
                temp+=s[j];
                if(checkPalindrome(temp))cnt++;
            }
        }

        return cnt;
    }
};