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
    int getHeight(TreeNode* root)
    {
        if(root==NULL)return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if(abs(left-right) > 1)return false;

        bool complete_left = isBalanced(root->left);
        bool complete_right = isBalanced(root->right);
        return complete_left and complete_right;
    }
};