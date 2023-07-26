class Solution {
public:
    int strStr(string s, string t) {
           int i = 0 ;
            int j = 0 ;

            int n  = s.size();
            int m  = t.size();
            int x;
            while (i < n and j < m )
            {
              
                if (s[i] == t[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i=i-j+1;
                    j=0;
                }
            }
            if(j==m)return i-j;
                        return -1;
    }
};