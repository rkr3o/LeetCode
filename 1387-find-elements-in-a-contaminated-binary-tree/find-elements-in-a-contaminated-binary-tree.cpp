class FindElements {
public:
    unordered_map<int, bool> mp;
    FindElements(TreeNode* root) {
        if (root) {
            root->val = 0;
            recover(root);
        }
    }
    
    void recover(TreeNode* node) {
        if (node == nullptr) return;
        
        mp[node->val] = true;
        
        if (node->left) {
            node->left->val = 2 * node->val + 1;
            recover(node->left);
        }
        
        if (node->right) {
            node->right->val = 2 * node->val + 2;
            recover(node->right);
        }
    }
    
    bool find(int target) {
        return mp.find(target) != mp.end();
    }
};
