/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root , TreeNode* a , TreeNode* b)
    {
        if(root==NULL || root==a || root==b)return root;
       
        TreeNode* left = lca(root->left,a,b);
        TreeNode* right = lca(root->right,a,b);
        
        if(left!=NULL and right!=NULL)return root;
        else if(left==NULL)return  right;
        else if(right==NULL)return  left;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return root;
        return lca(root,p,q);
    }
};