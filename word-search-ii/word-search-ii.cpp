struct Node
{
    Node *links[26];
    bool flag = false;
    string str;
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    public:
        Node * root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
        node->str = word;
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }

            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }

            node = node->get(prefix[i]);
        }
        return true;
    }
};

class Solution
{
    public:
        vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
        {
            int n = board.size();
            int m = board[0].size();

            Trie trie;
            for (string word: words)
            {
                trie.insert(word);
            }

            set<string> res;
            vector<vector < bool>> vis(n, vector<bool> (m, false));

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dfs(board, i, j, trie.root, res, vis);
                }
            }

            vector<string> ans(res.begin(), res.end());
            return ans;
        }

    private:
        void dfs(vector<vector < char>> &board, int i, int j, Node *node, set< string > &res, vector< vector< bool>> &vis)
        {
            node = node->get(board[i][j]);
            if (vis[i][j] || !node)
            {
                return;
            }
            if (node->isEnd())
            {
                res.insert(node->str);
            }
            vis[i][j] = true;

           	// Array values of direction (dx, dy)
            int drow[]={-1,0,+1,0};
            int dcol[]={0,+1,0,-1};
            for (int k = 0; k < 4; k++)
            {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];
                if(nrow>=0 and ncol>=0 and nrow<board.size() and ncol<board[0].size()and !vis[nrow][ncol])
                    dfs(board, nrow, ncol, node, res, vis);
            }
            vis[i][j] = false;
        }
};