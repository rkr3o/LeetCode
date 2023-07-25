struct Node {
    Node* links[26];
    bool end = false;

    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    bool containKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    void setEnd() {
        end = true;
    }
    
    bool isEnd() {
        return end;
    }
};

class Trie {
private:
   

public: 
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (string& word : wordDict) {
            trie.insert(word);
        }

        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            Node* cur = trie.root; // Use Node* instead of TrieNode*
            for (int j = i + 1; j <= n; j++) {
                char c = s[j - 1]; // Use A[j-1] instead of s[j-1]
                if (!cur->containKey(c)) { // Use containKey instead of search
                    break; // A[i:j] does not exist in our trie
                }
                cur = cur->get(c);
                if (cur->isEnd() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};