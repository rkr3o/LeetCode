class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        if (len1 > len2) {
            return false; // s1 cannot be included in s2 if it's longer
        }

        // Create frequency arrays for both strings
        vector<int> count1(26, 0); // Assuming only lowercase English letters
        vector<int> count2(26, 0);

        // Initialize the frequency arrays for the first window
        for (int i = 0; i < len1; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        for (int i = len1; i < len2; ++i) {
            // Check if the current window is a permutation of s1
            if (count1 == count2) {
                return true;
            }

            // Update the frequency array for the sliding window
            count2[s2[i] - 'a']++;
            count2[s2[i - len1] - 'a']--;
        }

        // Check for the last window
        if (count1 == count2) {
            return true;
        }

        return false;
    }
};