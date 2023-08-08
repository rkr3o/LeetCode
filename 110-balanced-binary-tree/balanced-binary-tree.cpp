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
        //abs(leftHeight-rightRight) <=1

        if(root==NULL)return true;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        return (abs(lh-rh)<=1) and left and right;
    }
};