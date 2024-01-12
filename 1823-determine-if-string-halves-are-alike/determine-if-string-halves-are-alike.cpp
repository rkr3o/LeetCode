class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I'||c=='O'||c=='U')
           return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        if(s.size()%2==1)return false;
        int n = s.size();
        int cnt = 0;
        int cnt2 = 0 ;
        for(int i =0 ; i < n/2 ; i++)
        {
            if(isVowel(s[i]))
                cnt++;
            if(isVowel(s[n-i-1]))
                cnt2++;
        }
        
        return cnt==cnt2;
    }
};