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
     int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int sum = 0;

        // Check if the left child is a leaf node and add its value to the sum
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }

        // Recursively traverse both left and right subtrees
        sum += solve(root->left);
        sum += solve(root->right);

        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
       
         return solve(root);;
    }
};