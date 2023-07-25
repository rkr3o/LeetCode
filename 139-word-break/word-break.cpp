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
    int dp[300];
    bool solve(int ind , string &s , Trie &trie)
    {
         if(ind==s.size())return true;
         string st;
         if(dp[ind]!=-1)return dp[ind];
         for(int i = ind ; i < s.size() ; i++)
         {
             st+=s[i];
             if(trie.search(st) and solve(i+1,s,trie)==true)return dp[ind]= true;
         }
         return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        memset(dp,-1,sizeof(dp));
        for(string word : wordDict)
            trie.insert(word);
         return solve(0,s,trie);
    }
};