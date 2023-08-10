/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root)
    {
         if (root == nullptr) {
            return 0;
        }
        
        // If the current node is a leaf, return 1
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        // If the left subtree is empty, consider only the right subtree
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        
        // If the right subtree is empty, consider only the left subtree
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        
        // If both subtrees are present, return the minimum depth
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
    int minDepth(TreeNode* root) {
         return solve(root);
    }
};