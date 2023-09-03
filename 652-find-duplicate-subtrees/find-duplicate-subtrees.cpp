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
string solve(TreeNode* root , vector<TreeNode*>&ans , map<string,int>&mp)
{
    if(root==NULL)return "#";
    string leftSubpart = solve(root->left,ans,mp);
    string rightSubpart= solve(root->right,ans,mp);
    string subpart = to_string(root->val)+"," + leftSubpart+ "," +rightSubpart;
    if(mp[subpart]==1)
    {
        ans.push_back(root);
    }
    mp[subpart]++;
    return subpart;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int>mp;
        vector<TreeNode*>ans;
        solve(root,ans,mp);
        return ans;
    }
};