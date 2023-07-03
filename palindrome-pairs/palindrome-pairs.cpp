class Solution {
public:
    bool isPalindrome(const string& word, int start, int end) {
        while (start <= end) {
            if (word[start++] != word[end--])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> wordIndices;

        // Store the indices of words in the hashmap
        for (int i = 0; i < words.size(); i++) {
            wordIndices[words[i]] = i;
        }

        // Iterate over the words
        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];
            int len = word.size();

            // Check for pairs with word as the left part
            for (int j = 0; j <= len; j++) {
                if (isPalindrome(word, 0, j - 1)) {
                    string revRight = word.substr(j);
                    reverse(revRight.begin(), revRight.end());
                    if (wordIndices.count(revRight) && wordIndices[revRight] != i) {
                        ans.push_back({ wordIndices[revRight], i });
                    }
                }
            }

            // Check for pairs with word as the right part
            for (int j = 0; j < len; j++) {
                if (isPalindrome(word, j, len - 1)) {
                    string revLeft = word.substr(0, j);
                    reverse(revLeft.begin(), revLeft.end());
                    if (wordIndices.count(revLeft) && wordIndices[revLeft] != i) {
                        ans.push_back({ i, wordIndices[revLeft] });
                    }
                }
            }
        }

        return ans;
    }
};
