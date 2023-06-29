class Solution
{
    public:
        void dfs(TreeNode *node, int target, long long currSum, int &count)
        {
            if (node == nullptr) return;
            currSum += node->val;
            if (currSum == target)
                count++;
            dfs(node->left, target, currSum, count);
            dfs(node->right, target, currSum, count);
        }
    int pathSum(TreeNode *root, int t)
    {
        if (root == nullptr) return 0;
        int cnt = 0;
        dfs(root, t, 0, cnt);
        int leftCount = pathSum(root->left, t);	// Recurse on the left subtree
        int rightCount = pathSum(root->right, t);	// Recurse on the right subtree
        return cnt + leftCount + rightCount;
    }
};