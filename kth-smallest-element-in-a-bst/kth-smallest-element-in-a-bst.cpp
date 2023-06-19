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
    void getInorder(TreeNode* root , vector<int>&inOrder)
    {
         if(root==NULL)return ;
         getInorder(root->left,inOrder);
         inOrder.push_back(root->val);
         getInorder(root->right,inOrder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        getInorder(root,inorder);
        return inorder[k-1];
    }
};