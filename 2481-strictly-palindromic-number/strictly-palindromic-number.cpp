class Solution {
public:
    bool checkPalindrone(string s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        return s==t;
    }
    string getBinary(int n , int b)
    {
        string s="";
        while(n>0)
        {
            int temp = n%b;
            s = to_string(temp)+s;
            n/=b;
        }
        return (s);
    }
    bool isStrictlyPalindromic(int n) {
          for(int i = 2 ; i<=n-2 ; i++)
          {
              string val = getBinary(n,i);
              if(checkPalindrone(val)==false)
                return false;
          }
          return true;
    }
};