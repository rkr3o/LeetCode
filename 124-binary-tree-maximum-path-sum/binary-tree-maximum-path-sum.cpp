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
    int findMaxPathSum(TreeNode* root , int &maxima)
    {
        if (root == NULL) return 0;
        int leftMaxPath = max(0, findMaxPathSum(root -> left, maxima));
        int rightMaxPath = max(0, findMaxPathSum(root -> right, maxima));
        int val = root -> val;
        maxima = max(maxima, (leftMaxPath + rightMaxPath + val));
        return root->val+max(leftMaxPath, rightMaxPath);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)return 0 ; 
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }
};