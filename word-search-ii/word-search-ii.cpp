class TrieNode {
public:
    vector<TrieNode*> children;
    string word;

    TrieNode() : children(26), word("") {}
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }

        vector<string> result;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                backtrack(board, visited, trie.root, i, j, result);
            }
        }

        return result;
    }

private:
    void backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, TrieNode* node, int row, int col, vector<string>& result) {
        char c = board[row][col];
        int idx = c - 'a';

        if (!node->children[idx]) {
            return;
        }

        node = node->children[idx];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // Mark word as found (avoid duplicates)
        }

        visited[row][col] = true;

        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol]) {
                backtrack(board, visited, node, newRow, newCol, result);
            }
        }

        visited[row][col] = false;
    }
};
