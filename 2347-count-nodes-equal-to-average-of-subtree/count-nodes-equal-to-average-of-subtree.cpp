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
    pair<int, int> sum(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        
        pair<int, int> leftSum = sum(root->left);
        pair<int, int> rightSum = sum(root->right);
        
        int totalSum = leftSum.first + rightSum.first + root->val;
        int totalCount = leftSum.second + rightSum.second + 1;
        
        return {totalSum, totalCount};
    }
    
    double averageOfSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0.0;
        }
        
        pair<int, int> nodeSum = sum(root);
        int totalSum = nodeSum.first;
        int totalCount = nodeSum.second;
        int cnt = 0 ;
        if(totalSum/totalCount==root->val)cnt++;
        cnt+=averageOfSubtree(root->left);
        cnt+=averageOfSubtree(root->right);
        return cnt;
    }
};
