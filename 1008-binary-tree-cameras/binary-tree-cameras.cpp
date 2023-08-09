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
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        // The return value of dfs is:
        // 0: Node is covered by a camera.
        // 1: Node needs a camera.
        // 2: Node has a camera.
        return (dfs(root, cameras) == 1) ? cameras + 1 : cameras;
    }

    int dfs(TreeNode* node, int& cameras) {
        if (!node) return 0;

        int leftStatus = dfs(node->left, cameras);
        int rightStatus = dfs(node->right, cameras);

        if (leftStatus == 1 || rightStatus == 1) {
            cameras++; // Place a camera at this node.
            return 2; // Node has a camera.
        } else if (leftStatus == 2 || rightStatus == 2) {
            return 0; // Node is covered by adjacent camera.
        } else {
            return 1; // Node is not covered and needs a camera.
        }
    }
};
