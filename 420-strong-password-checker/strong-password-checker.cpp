class Solution {
    
    int getRequiredChar(string s) {
        int lowercase = 1, uppercase = 1, digit = 1;
        for (char c : s) {
            if (islower(c)) lowercase = 0;
            else if (isupper(c)) uppercase = 0;
            else if (isdigit(c)) digit = 0;
        }
        return lowercase + uppercase + digit;
    }
    
    void countRepeatingGroups(string s, int &replace, int &oned, int &twod) {
        for (int i = 0; i < s.length(); ) {
            int len = 1;
            while (i + len < s.length() && s[i + len] == s[i + len - 1]) len++;
            if (len >= 3) {
                replace += len / 3;
                if (len % 3 == 0) oned++;
                else if (len % 3 == 1) twod += 2;
            }
            i += len;
        }
    }
    
public:
    int strongPasswordChecker(string s) {
        int requiredChar = getRequiredChar(s);
        int n = s.length();

        if (n < 6) return max(requiredChar, 6 - n);
        
        int replace = 0, oned = 0, twod = 0;
        countRepeatingGroups(s, replace, oned, twod);

        if (n <= 20) return max(requiredChar, replace);

        int deleteCount = n - 20;
        replace -= min(deleteCount, oned);
        replace -= min(max(deleteCount - oned, 0), twod) / 2;
        replace -= max(deleteCount - oned - twod, 0) / 3;

        return deleteCount + max(requiredChar, replace);
    }
};
