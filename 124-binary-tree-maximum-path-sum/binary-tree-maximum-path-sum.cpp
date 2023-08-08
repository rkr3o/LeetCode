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
    int getMaxPathSum(TreeNode* root, int &maxSum) {
        if (root == nullptr)
            return 0;

        int leftSum = getMaxPathSum(root->left, maxSum);
        int rightSum = getMaxPathSum(root->right, maxSum);
        
        // Include the current node in the path or start a new path
        int pathSum = max(root->val, max(root->val + leftSum, root->val + rightSum));
        
        // Update the global maxSum
        maxSum = max(maxSum, max(pathSum, root->val + leftSum + rightSum));

        return pathSum;
    }
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int maxSum = INT_MIN;
        getMaxPathSum(root, maxSum);
        return maxSum;
    }
};
