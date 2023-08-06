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
    int dfs(TreeNode* node, int ancestorMin, int ancestorMax) {
        if (!node) return ancestorMax - ancestorMin;

        // Update ancestorMin and ancestorMax for the current node
        ancestorMin = min(ancestorMin, node->val);
        ancestorMax = max(ancestorMax, node->val);

        // Recursively calculate the maximum difference in the left and right subtrees
        int leftDiff = dfs(node->left, ancestorMin, ancestorMax);
        int rightDiff = dfs(node->right, ancestorMin, ancestorMax);

        // Return the maximum difference among the current node's subtree and its subtrees
        return  max(leftDiff, rightDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val, root->val);
    }
};