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
    void getInorder(TreeNode* root , vector<int>&v)
    {
        if(root==NULL)return;
        getInorder(root->left,v);
        v.push_back(root->val);
        getInorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>a;
        vector<int>b;
        getInorder(root1,a);
        getInorder(root2,b);
        int n = a.size();
        int m = b.size();
        a.push_back(1e9+7);
        b.push_back(1e9+7);
        vector<int>ans(n + m);
        int i = 0 , j = 0  , k = 0 ;
        while (k < n + m)
        {
            if (a[i] <= b[j])
            {
                ans[k++] = a[i++];
            }
            else
            {
                ans[k++] = b[j++];
            }
        }
        return ans;
    }
};