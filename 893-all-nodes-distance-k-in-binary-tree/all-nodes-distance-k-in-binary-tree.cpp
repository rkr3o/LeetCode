/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        void mark_parent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &mp)
        {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if (node->right)
                {
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> mp;
        mark_parent(root, mp);

        int cnt = 0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = true;
        while (!q.empty())
        {
            int size = q.size();
            if (cnt++ == k) break;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
               
                q.pop();
                if (node->left and!vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right and!vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (mp[node] and!vis[mp[node]])
                {
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            ans.push_back(x->val);
        }
        return ans;
    }
};