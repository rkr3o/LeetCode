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
    void getSum(TreeNode* root , int &sum , int &cntElements)
    {
        if(root==NULL)return;
        sum+=root->val;
        cntElements++;
        getSum(root->left,sum,cntElements);
        getSum(root->right,sum,cntElements);
    }
    double averageOfSubtree(TreeNode* root) {
        if(root==NULL)return 0.0;
        int cnt = 0 ;
        int sum = 0 ;
        int cntElements = 0 ;
        getSum(root,sum,cntElements);
        int avg =sum/cntElements;
        if(avg ==root->val)cnt++;
        cnt+=averageOfSubtree(root->left);
        cnt+=averageOfSubtree(root->right);
        return cnt;
    }
};