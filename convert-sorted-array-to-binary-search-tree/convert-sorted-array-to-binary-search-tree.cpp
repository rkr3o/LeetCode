 
class Solution {
public:
    TreeNode* constructBST(vector<int>& nums, int start, int end) 
    {
        if (start > end) 
        {
            return nullptr;
        }
        int mid = start + (end - start) / 2;  // Calculate the middle index
        TreeNode* root = new TreeNode(nums[mid]);  // Create a new node with the middle element as the root
        // Recursively construct the left and right subtrees
        root->left = constructBST(nums, start, mid - 1);
        root->right = constructBST(nums, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }
};
