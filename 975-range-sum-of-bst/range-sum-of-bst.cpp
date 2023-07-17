class Solution {
public:
   int countBST(TreeNode* root, int l , int h)
    {
        if(root==NULL)return 0 ;
        int sum = 0 ;
        if(root->val>=l and root->val<=h)
        {
            return root->val+countBST(root->left,l,h)+countBST(root->right,l,h);
        }
        else if (root->val < l)
            return countBST(root->right, l, h);
        // If the current node's value is greater than the range, recursively search the left subtree
        else
            return countBST(root->left, l, h);
    }
    int rangeSumBST(TreeNode* root, int l, int h) {
        if(root==NULL)return 0;
        return countBST(root,l,h);
    }
};
