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
    void solve(TreeNode* root , int t , vector<int>&ds , vector<vector<int>>&ans)
    {
        if(root==NULL)return;
        ds.push_back(root->val);
        if(t==root->val and root->left==NULL and root->right==NULL)
        {
            ans.push_back(ds);
        }
       solve(root->left, t - root->val,ds,ans);
       solve(root->right, t - root->val,ds,ans); 
       ds.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        if(root->val!=target and root->left==NULL and root->right==NULL)return ans;
        vector<int>ds;
        solve(root,target,ds,ans);
        return ans;
    }
};