class Solution {
public:
    unordered_map<TreeNode*, int> dp; // Dynamic programming map

    int solve(TreeNode* root) {
        if (root == nullptr) return 0;

        if (dp.find(root) != dp.end()) {
            return dp[root];
        }

        int pick = root->val;
        if (root->left) {
            pick += (solve(root->left->left) + solve(root->left->right));
        }
        if (root->right) {
            pick += (solve(root->right->left) + solve(root->right->right));
        }
        int notPick = solve(root->left) + solve(root->right);
        dp[root] = max(pick, notPick);
        return dp[root];
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};
