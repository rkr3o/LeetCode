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
    int height(TreeNode *root){
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));
}
    int diameter(TreeNode *root ){
    if(root==NULL)return 0;
    int d1=1+height(root->left)+height(root->right);
    int d2=diameter(root->left);
    int d3=diameter(root->right);
    
    return max(d1,max(d2,d3));
}

    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans  = diameter(root);
        
        return  ans-1;
         
    }
};