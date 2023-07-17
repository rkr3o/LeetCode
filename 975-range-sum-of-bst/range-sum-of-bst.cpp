class Solution {
public:
    void getInorder(TreeNode* root, vector<int>& in) {
        if (root == NULL)
            return;

        getInorder(root->left, in);
        in.push_back(root->val);
        getInorder(root->right, in);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> in;
        getInorder(root, in);
        if (root == NULL)
            return 0;

        int count = 0;
        int n = in.size();
        int sum = 0;

        // Adjust low and high if they are out of range
        if (low < in[0])
            low = in[0];
        if (high > in[n - 1])
            high = in[n - 1];

        for (int i = 0; i < n; i++) {
            if (in[i] >= low && in[i] <= high)
                sum += in[i];
        }

        return sum;
    }
};
