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
    void solve(TreeNode* root , int &ans , int &cnt , int k)
    {
        if(root==NULL)return ;
        solve(root->left,ans,cnt,k);
        if(cnt==k)
        {
            ans=root->val;
            cnt++;
            return;
        }
        else
        {
            cnt++;
        }
        solve(root->right,ans,cnt,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return -1;
        int idx=  1;
        int ans = -1;
        
        solve(root,ans,idx,k);
        return ans;
    }
};