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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
      
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        int cnt = 0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            cnt++;
            vector<int>ds;
            for(int i = 0 ; i < n ;i++)
            {       
                TreeNode* node = q.front();
                q.pop();
                ds.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                

            }
           if(cnt%2==0)reverse(ds.begin(),ds.end());
           ans.push_back(ds);
           ds.clear();
        }

        return ans;
    }
};