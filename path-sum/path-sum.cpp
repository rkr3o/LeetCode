class Solution {
public:
    bool solve(TreeNode* root, int t) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL && t - root->val == 0)
            return true;
        
        bool left = solve(root->left, t - root->val);
        bool right = solve(root->right, t - root->val);
        
        return left || right; // Fix: Return true if either left or right path has a valid sum
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        return solve(root, sum);
    }
};
