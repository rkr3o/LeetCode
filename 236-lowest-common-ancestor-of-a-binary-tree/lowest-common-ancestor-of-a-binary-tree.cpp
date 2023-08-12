/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* target, vector<int>& path) {
        if (root == nullptr) {
            return false;
        }
        
        path.push_back(root->val);
        
        if (root == target) {
            return true;
        }
        
        if ((getPath(root->left, target, path)) ||
            (getPath(root->right, target, path))) {
            return true;
        }
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1, path2;
        
        if (!getPath(root, p, path1) || !getPath(root, q, path2)) {
            return nullptr; // One or both nodes not found
        }
        
        TreeNode* lca = nullptr;
        int n = min(path1.size(), path2.size());
        
        for (int i = 0; i < n; ++i) {
            if (path1[i] == path2[i]) {
                lca = new TreeNode(path1[i]);
            } else {
                break;
            }
        }
        
        return lca;
    }
};