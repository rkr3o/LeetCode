class Solution {
public:
    int partitionString(string s) {
        vector<int> hsh(26, 0);
        int cnt = 1; 
        for (int i = 0; i < s.size(); i++) {
            if (hsh[s[i] - 'a'] > 0) {
                cnt++;
                fill(hsh.begin(), hsh.end(), 0);
            }
            hsh[s[i] - 'a']++;
        }
        return cnt;
    }
};
