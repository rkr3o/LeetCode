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
        for(string word : wordDict)
            trie.insert(word);
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        for(int len=1; len<=s.size(); len++){
            for(int i=0; i<len; i++){
                if(dp[i] && trie.search(s.substr(i, len-i)))
                    dp[len]=true;
            }
        }
        return dp[s.size()];
    }
};