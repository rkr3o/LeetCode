class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode('\0');
    }

    void insertWordUtil(TrieNode* root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        if (root->children[index] != NULL) {
            // Child is present
            child = root->children[index];
        } else {
            // Child is absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive function
        insertWordUtil(child, word.substr(1));
    }

    void addWord(string word) {
        insertWordUtil(root, word);
    }

    bool searchUtil(TrieNode* curr, string word, int index) {
        // Base case
        if (index == word.size()) {
            return curr->isTerminal;
        }

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] && searchUtil(curr->children[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int charIndex = ch - 'a';
            if (curr->children[charIndex]) {
                return searchUtil(curr->children[charIndex], word, index + 1);
            }
            return false;
        }
    }

    bool search(string word) {
        return searchUtil(root, word, 0);
    }
};
