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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;

        if (root->val < low) {
            // If the root's value is less than low, recursively trim right subtree
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            // If the root's value is greater than high, recursively trim left subtree
            return trimBST(root->left, low, high);
        }

        // Trim both left and right subtrees and update root's children
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
