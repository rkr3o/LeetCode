class Solution {
public:
    int dp[1000];
    bool isPalindrome(string s) {
       string t = s;
       reverse(t.begin(),t.end());
       return s==t;
    }
    int countPalindromicSubstrings(int ind, string &s) {
        if (ind >= s.size()) {
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int cnt = 0;
        string temp = "";
        for (int i = ind; i < s.size(); i++) {
            temp += s[i];
            if (isPalindrome(temp)) {
                cnt++;  // Increment the count when a palindrome is found.
            }
        }
        // Recursively count palindromic substrings starting from the next index.
        cnt += countPalindromicSubstrings(ind + 1, s);
        return dp[ind]= cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return countPalindromicSubstrings(0, s);
    }
};
