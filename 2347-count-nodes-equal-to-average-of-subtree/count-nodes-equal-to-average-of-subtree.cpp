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
    int ans = 0 ;
    pair<int,int>solve(TreeNode* root)
    {
        if(root==NULL)return {0,0};
        pair<int,int>left = solve(root->left);
        int lc = left.second;
        int ls = left.first;
        pair<int,int>right = solve(root->right);
        int rc = right.second;
        int rs = right.first;
        int sum = ls+rs+root->val;
        int cnt = 1+rc+lc;
        if(root->val==sum/cnt)ans++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};