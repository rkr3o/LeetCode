class Solution {
public:
    void convertBSTUtil(TreeNode* root, int& sum) {
        if (root == nullptr) return;

        convertBSTUtil(root->right, sum); // Traverse right subtree
        
        sum += root->val; // Update sum
        
        root->val = sum; // Update current node's value
        
        convertBSTUtil(root->left, sum); // Traverse left subtree
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBSTUtil(root, sum);
        return root;
    }
};
