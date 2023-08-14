class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;

        if (root->val < low) {
            // If root's value is less than low, the trimmed tree will be in the right subtree
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            // If root's value is greater than high, the trimmed tree will be in the left subtree
            return trimBST(root->left, low, high);
        } else {
            // Root's value is within the range, so recursively trim both left and right subtrees
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};
