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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)return 0;
        int ans = 0 ;
        queue<pair<TreeNode* , int >>q;
        q.push({root,0});
        while(!q.empty())
        {
            int minElem = q.front().second;
            int n = q.size();
            int last , first;
            for(int i = 0 ; i < n ; i++)
            {
                TreeNode* node = q.front().first;
                int curInd = q.front().second-minElem;
                q.pop();

                if(i==0)first = curInd;
                if(i==n-1)last = curInd;

                if(node->left)
                {
                    q.push({node->left,(long long)curInd*2+1});
                }
                if(node->right)
                {
                    q.push({node->right,(long long)curInd*2+2});
                }
            }
             ans = max(ans,last-first+1);
        } 
        return ans;
    }
};