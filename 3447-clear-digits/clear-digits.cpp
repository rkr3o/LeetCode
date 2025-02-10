class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        int j = 0; 
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                if (j > 0) {
                    j--; 
                }
            } else {
                s[j] = s[i];
                j++;
            }
        }
        return s.substr(0, j);
    }
};
