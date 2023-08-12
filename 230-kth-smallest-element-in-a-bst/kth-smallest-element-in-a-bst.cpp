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
    int solve(TreeNode* root, int& k) {
        if (root == nullptr) {
            return -1; // Using -1 to indicate that we haven't found the kth element yet.
        }
        
        int left = solve(root->left, k);
        if (k == 0) {
            return left; // Return the found kth element.
        }
        
        k--;
        
        if (k == 0) {
            return root->val; // Return the current node's value as kth element.
        }
        
        return solve(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k);
    }
};
