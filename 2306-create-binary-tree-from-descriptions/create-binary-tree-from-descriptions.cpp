
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;
        
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];
            
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parentNode = nodeMap[parentVal];
            
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }
            TreeNode* childNode = nodeMap[childVal];
            
            if (isLeft) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
            
            children.insert(childVal);
        }
        
        TreeNode* root = nullptr;
        for (const auto& desc : descriptions) {
            if (children.find(desc[0]) == children.end()) {
                root = nodeMap[desc[0]];
                break;
            }
        }
        
        return root;
    }
};