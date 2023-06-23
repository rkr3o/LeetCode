class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxSum = INT_MIN;
        getMaxPathSum(root, maxSum);

        return maxSum;
    }

private:
    int getMaxPathSum(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        int leftSum = getMaxPathSum(node->left, maxSum);
        int rightSum = getMaxPathSum(node->right, maxSum);

        // Calculate the sum of the current path
        int currentSum = node->val + max(0, leftSum) + max(0, rightSum);

        // Update the maximum sum if the current path is greater
        maxSum = max(maxSum, currentSum);

        // Return the maximum sum of the current node's subtree
        return node->val + max(0, max(leftSum, rightSum));
    }
};