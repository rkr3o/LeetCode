class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push({0, {0, root}});
        
        while (!q.empty()) {
            auto x = q.front();
            int hd = x.first;
            int lvl = x.second.first;
            TreeNode* node = x.second.second;
            q.pop();
            
            mp[hd][lvl].insert(node->val);
            
            if (node->left) {
                q.push({hd - 1, {lvl + 1, node->left}});
            }
            if (node->right) {
                q.push({hd + 1, {lvl + 1, node->right}});
            }
        }
        
        vector<vector<int>> ans;
        for (auto x : mp) {
            vector<int> column;
            for (auto y : x.second) {
                for (auto z : y.second) {
                    column.push_back(z);
                }
            }
            ans.push_back(column);
        }
        
        return ans;
    }
};
