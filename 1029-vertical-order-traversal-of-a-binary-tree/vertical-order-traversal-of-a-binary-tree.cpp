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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<int,pair<int,TreeNode*>>>q;
        q.push({0,{0,root}});
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            int hd= x.first;
            int lvl = x.second.first;
            TreeNode* node = x.second.second;
            mp[hd][lvl].insert(node->val);

            if(node->left)
            {
                q.push({hd-1,{lvl+1,node->left}});
            }
            if(node->right)
            {
                q.push({hd+1,{lvl+1,node->right}});
            }
        }

    for(auto x : mp)
    {
        vector<int>temp;
        for(auto y : x.second)
        {
            for(auto z : y.second)
            {
                 temp.push_back(z);
            }
        }
        ans.push_back(temp);
    }

    return ans;
    }
};