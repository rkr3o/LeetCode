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

    vector<int> dfs(TreeNode* node, int distance, int& result) {
        // Base case: return an empty vector for null nodes
        if (!node) {
            return {};
        }

        // If it is a leaf node, return a vector with a single element, which is the distance to itself
        if (!node->left && !node->right) {
            return {0};
        }

        // Recursively calculate the distances for left and right subtrees
        auto leftDistances = dfs(node->left, distance, result);
        auto rightDistances = dfs(node->right, distance, result);

        // Combine distances from left and right subtrees to check for good leaf node pairs
        for (int left : leftDistances) {
            for (int right : rightDistances) {
                if (left + right + 2 <= distance) {
                    result++;
                }
            }
        }

        // Increment all distances and remove distances greater than distance
        vector<int> combinedDistances;
        for (int dist : leftDistances) {
            if (dist + 1 <= distance) {
                combinedDistances.push_back(dist + 1);
            }
        }
        for (int dist : rightDistances) {
            if (dist + 1 <= distance) {
                combinedDistances.push_back(dist + 1);
            }
        }

        return combinedDistances;
    }
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }
};