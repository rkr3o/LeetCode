class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxCount = 0;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            mp[s[right]]++;
            maxCount = max(maxCount, mp[s[right]]);
            while (right - left + 1 - maxCount > k) {
                mp[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};