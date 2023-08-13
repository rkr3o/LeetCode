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
    void getInorder(TreeNode* root , vector<int>&in)
    {
         if(root==NULL)return ;
         getInorder(root->left,in);
         in.push_back(root->val);
         getInorder(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {
        
        if(root==NULL)return false;
        vector<int>in;
        getInorder(root,in);
        int i = 0 , j = in.size()-1;
        while(i<j)
        {
            if(in[i]+in[j]==k)return true;
            else if(in[i]+in[j]>k)
            {
                j--;
            }
            else 
            {
                i++;
            }
        }
       return false;
    }
};
