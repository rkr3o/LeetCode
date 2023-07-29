class Solution {
public:
     bool checkPalindrome(string &s)
    {
        int st = 0 ;
        int end = s.size()-1;
        while(st<=end)
        {
            if(s[st++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
       string maxima="";
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            string cur;
            for(int j = i ; j < n ;j++)
            {
                cur+=s[j];
                if(checkPalindrome(cur)==true and cur.size() > maxima.size())
                {
                    maxima = cur;
                }
            }
        }
        return maxima;
    }
};
