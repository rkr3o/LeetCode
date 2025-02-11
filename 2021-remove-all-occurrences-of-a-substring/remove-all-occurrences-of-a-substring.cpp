class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();
        string result = "";
        
        for (int i = 0; i < n; ++i) {
            result.push_back(s[i]);
            if (result.size() >= m && result.substr(result.size() - m, m) == part) {
                result.erase(result.size() - m, m);
            }
        }
        
        return result;
    }
};
