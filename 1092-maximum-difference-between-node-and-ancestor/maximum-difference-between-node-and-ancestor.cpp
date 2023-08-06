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
    int solve(TreeNode* root , int rootData)
    {
        if(root==NULL)return 0 ;
        int maxima = INT_MIN;
        maxima = max(maxima ,abs(root->val- rootData));
        maxima = max(maxima,solve(root->left,rootData));
        maxima = max(maxima,solve(root->right,rootData));
        return maxima;
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        int ans = INT_MIN;
        int data = solve(root,root->val);
        int left = maxAncestorDiff(root->left);
        int right = maxAncestorDiff(root->right);
        ans = max({data,left,right});
        return ans;
    }
};