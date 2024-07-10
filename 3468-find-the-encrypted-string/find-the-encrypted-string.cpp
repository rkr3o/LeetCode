class Solution {
public:
    string getEncryptedString(string s, int k) {
       int n = s.size();
        string result(n, ' '); 
        for (int i = 0; i < n; i++) {
            result[i] = s[(i + k) % n];
        }
        return result;
    }
};