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
    TreeNode* solve(TreeNode* root , int x)
    {
        if(root==NULL)return NULL;
        if(root->val==x)return root;
        if(root->val < x)
        {
            return solve(root->right,x);
        }
        else
        {
            return solve(root->left,x);
        }
    }
    TreeNode* searchBST(TreeNode* root, int x) 
    {
        return solve(root,x);
    }
};