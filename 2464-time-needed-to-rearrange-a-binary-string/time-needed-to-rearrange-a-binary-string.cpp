class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0 ;
        while (true) {
            bool f = false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    i++;
                    f = true;
                }
            }
            if (!f) break;
            else cnt++;
        } 
        return cnt;
    }
};
