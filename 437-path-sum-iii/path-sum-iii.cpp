/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void solve(TreeNode *root, int t, int &cnt, vector<int> &path)
        {
            if (root == NULL) return;
            path.push_back(root->val);
            solve(root->left, t, cnt, path);
            solve(root->right, t, cnt, path);
            long long int sum = 0;
            int s = path.size();
            for (int i = s - 1; i >= 0; i--)
            {
                sum += path[i];
                if (sum == t)
                    cnt++;
            }
            path.pop_back();
        }
    int pathSum(TreeNode *root, int t)
    {
        vector<int> path;
        int cnt = 0;
          solve(root, t, cnt, path);
          return cnt;
    }
};