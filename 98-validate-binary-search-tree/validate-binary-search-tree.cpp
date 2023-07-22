class Solution {

    bool solve(TreeNode* root , long long x , long long y)
    {
        if(root==NULL)return true;

        if(root->val <= x || root->val>=y)
        {
            return false;
        }
        
        bool left =  solve(root->left,x,root->val);
        bool right = solve(root->right , root->val,y);
        
        return left and right;
    }
public:
    bool isValidBST(TreeNode* root) {
         
         long long x = LLONG_MIN;
         long long y = LLONG_MAX ;

         return solve(root,x,y);
    }
};