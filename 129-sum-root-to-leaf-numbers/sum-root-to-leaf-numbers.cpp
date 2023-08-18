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
    //const int mod =  1e9+7;
    void solve(TreeNode* root , int curSum , int &ans)
    {
        if(root==NULL)return;
        curSum = (curSum*10+root->val);
        if(root->left==NULL and root->right==NULL)
        {
            ans += curSum;
            return;
        }
        solve(root->left,curSum,ans);
        solve(root->right,curSum,ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans =0 ;
        solve(root,0,ans);
        return ans;
    }
};