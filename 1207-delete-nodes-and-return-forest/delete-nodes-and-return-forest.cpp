class Solution {
public:
    TreeNode* solve(TreeNode* root, unordered_set<int>& to_delete_set, vector<TreeNode*>& ans) {
        if (root == nullptr) return nullptr;

        root->left = solve(root->left, to_delete_set, ans);
        root->right = solve(root->right, to_delete_set, ans);

        if (to_delete_set.find(root->val) != to_delete_set.end()) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            delete root; 
            return nullptr;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        if (to_delete_set.find(root->val) == to_delete_set.end()) {
            ans.push_back(root); 
        }

        solve(root, to_delete_set, ans);

        return ans;
    }
};
