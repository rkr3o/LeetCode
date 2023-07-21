class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
       unordered_set<char>window;
       int maxima = 0;
       for (int right = 0 , left = 0 ; right < n; right++) 
       {
            if (window.find(s[right]) == window.end()) {
                window.insert(s[right]);
                maxima = max(maxima, right - left + 1);
            } else {
                while (s[left] != s[right]) {
                    window.erase(s[left]);
                    left++;
                }
                left++; // Move the left pointer one step ahead of the repeating character
            }
    }

    return maxima;
    }
};
